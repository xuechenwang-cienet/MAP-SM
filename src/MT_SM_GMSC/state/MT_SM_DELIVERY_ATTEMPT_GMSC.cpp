/*
 * MT_SM_DELIVERY_ATTEMPT_GMSC.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */


#include "AllState.h"

MT_SM_DELIVERY_ATTEMPT_GMSC::MT_SM_DELIVERY_ATTEMPT_GMSC() {

}

bool MT_SM_DELIVERY_ATTEMPT_GMSC::init(IContext* context) {

    if (context->is_ServingNodeGMSC()) {
        return context->pushState(StateHolder::getState(IStateTyp::MT_SM_TRANSFER_MSC));

    }
    if (context->is_MessageSegmentingNeeded()) {
        //SEND MAP_OPEN_REQ MAP_DELIMITER_REQ
        context->send_MAP_OPEN_REQ();
        context->send_MAP_DELIMITER_REQ();
        IState* state = StateHolder::getState(IStateTyp::RECEIVE_OPEN_CNF);
        if (NULL == state) {
            return false;
        }
        if (!context->pushState(state)) {
            return false;
        }
        return context->getCurrentState()->init(context);
    }
    if (context->is_TCAPHandshakeRequired()) {
        //SEND MAP_OPEN_REQ MAP_DELIMITER_REQ
        context->send_MAP_OPEN_REQ();
        context->send_MAP_DELIMITER_REQ();
        IState* state = StateHolder::getState(IStateTyp::RECEIVE_OPEN_CNF);
        if (NULL == state) {
            return false;
        }
        if (!context->pushState(state)) {
            return false;
        }
        return context->getCurrentState()->init(context);

    }
    //SEND MAP_OPEN_REQ MAP_MT_FORWARD_SHORT_MESSAGE_REQ MAP_DELIMITER_REQ
    context->send_MAP_OPEN_REQ();
    context->send_MAP_MT_FORWARD_SHORT_MESSAGE_REQ();
    context->send_MAP_DELIMITER_REQ();
    IState* state = StateHolder::getState(IStateTyp::RECEIVE_OPEN_CNF);
    if (NULL == state) {
        return false;
    }
    if (!context->pushState(state)) {
        return false;
    }
    return context->getCurrentState()->init(context);
}

bool MT_SM_DELIVERY_ATTEMPT_GMSC::handleEvent(IContext* context) {
    return false;
}

bool MT_SM_DELIVERY_ATTEMPT_GMSC::handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
    switch (ret) {
    case IEventTpy::OPEN_CNF_RESULT_Vr : {
        //PERFORM MAP Vr Dialogue //TODO ?
        if (context->is_SuccessfulDelivery()) {
            return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_PASS, context);
        }
        return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_FAIL, context);
    }
    case IEventTpy::OPEN_CNF_RESULT_OK : {
        if (context->is_MessageSegmentingNeeded()) {
            //SEND MAP_MT_FORWARD_SHORT_MESSAGE_REQ
            //SEND MAP_DELIMITER_REQ
            context->send_MAP_MT_FORWARD_SHORT_MESSAGE_REQ();
            context->send_MAP_DELIMITER_REQ();
        }
        return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_FIRST_MT_SMS_CONIFIRM));
    }
    case IEventTpy::OPEN_CNF_RESULT_ERR : {
        //SET RP_CAUSE: system failure
        //SEND SC_RP_ERROR_REQ
        context->send_SC_RP_ERROR_REQ("system failure");
        return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_FAIL, context);
    }
    //CHECK_CONFIRMATION
    case IEventTpy::CHECK_CONFIRMATION_RESULT_OK : {
        if (context->get_CHK_CNF_reason() != IStateTyp::WAIT_FOR_FIRST_MT_SMS_CONIFIRM) {
            return false;
        }
        if (context->is_MoreMessagesToSend()) {
            context->send_SC_RP_ACK_REQ();
            return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY));
        }
        if (context->is_MCEForMNRFsetInHLR()) {
            IState* state = StateHolder::getState(IStateTyp::REPORT_SM_DELIVERY_STAT_GMSC);
            if (NULL == state) {
                return false;
            }
            if (!context->pushState(state)) {
                return false;
            }
            return context->getCurrentState()->init(context);
        }
        context->send_SC_RP_ACK_REQ();
        return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_PASS, context);

    }
    case IEventTpy::CHECK_CONFIRMATION_RESULT_USER_ERR : {
        switch (context->get_CHK_CNF_UserErr_Cause()) {
        case IContext::CHK_CNF_USERERR_CAUSE_ELSE : {
            context->set_RP_ERRPR();
            context->send_SC_RP_ERROR_REQ();
            return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_FAIL, context);
        }
        case IContext::UNIDENTIFIED_SUBSCRIBER : {
            //TODO context->setUE(ABSENT_SUBSCRIBER)
        }
        case IContext::ABSENT_SUBSCRIBER :
        case IContext::MS_MEMORY_CAPACITY_EXCEEDED : {
            //TODO omit
            IState* state = StateHolder::getState(IStateTyp::REPORT_SM_DELIVERY_STAT_GMSC);
            if (NULL == state) {
                return false;
            }
            if (!context->pushState(state)) {
                return false;
            }
            return context->getCurrentState()->init(context);
        }
        }
        return false;
    }
    case IEventTpy::CHECK_CONFIRMATION_RESULT_DATA_ERR :
    case IEventTpy::CHECK_CONFIRMATION_RESULT_PROVIDER_ERR : {
        if (context->get_CHK_CNF_reason() != IStateTyp::WAIT_FOR_FIRST_MT_SMS_CONIFIRM) {
            return false;
        }
        context->set_RP_ERRPR();
        context->send_SC_RP_ERROR_REQ();
        return reportMacDefResult(IEventTpy::MT_SM_DLVRY_RESULT_FAIL, context);
    }
    default : {
        return false;
    }
    }
    return false;
}
