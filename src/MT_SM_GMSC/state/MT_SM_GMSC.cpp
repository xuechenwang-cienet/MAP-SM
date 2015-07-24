/*
 * MT_SM_GMSC.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#include "MT_SM_GMSC.h"

MT_SM_GMSC::MT_SM_GMSC() {
}

bool  MT_SM_GMSC::handleEvent(IContext* context) {
    if (NULL == context) {
        return false;
    }
    if (this != context->getCurrentState()) {
        return false;
    }
    context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    return context->getCurrentState()->handleEvent(context);

}

bool MT_SM_GMSC::handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
    if (NULL == context) {
        return false;
    }
    if (this != context->getCurrentState()) {
        return false;
    }
    switch (ret) {
    //OPEN_CNF_RESULT
    case IEventTpy::OPEN_CNF_RESULT_V1 : {
        if (context->is_RoutingInfoReceived()) {
            return context->pushState(StateHolder::getState(IStateTyp::MT_SM_DELIVERY_ATTEMPT_GMSC));
        }
        context->send_SC_RP_ERROR_REQ("");
        return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::OPEN_CNF_RESULT_OK : {
        return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_ROUTING_INFO));
    }
    case IEventTpy::OPEN_CNF_RESULT_ERR : {
        //SET RP_CAUSE: system failure
        //SEND SC_RP_ERROR_REQ
        context->send_SC_RP_ERROR_REQ("system failure");
        return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    //CHECK_CONFIRMATION
    case IEventTpy::CHECK_CONFIRMATION_RESULT_OK : {
        if (context->get_CHK_CNF_reason() != IStateTyp::WAIT_FOR_ROUTING_INFO) {
            return false;
        }
        if (context->is_LMSIIncludedInRoutingInfo()) {
            //SET destination reference: IMSI
            //SET SM_RP_DA: LMSI
            context->set_DestinationReference("IMSI");
            context->set_SM_RP_DAL("LMSI");
            return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_INFORM_SC));
        }
        //SET destination reference: not included
        //SET SM_RP_DA: LMSI
        context->set_DestinationReference("IMSI");
        context->set_SM_RP_DAL("LMSI");
        return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_INFORM_SC));
    }
    case IEventTpy::CHECK_CONFIRMATION_RESULT_USER_ERR : {
        if (context->get_CHK_CNF_reason() != IStateTyp::WAIT_FOR_ROUTING_INFO) {
            return false;
        }
        //SET RP_CAUSE
        context->set_RP_CAUSE("");
        return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_INFORM_SC));
    }
    case IEventTpy::CHECK_CONFIRMATION_RESULT_DATA_ERR :
    case IEventTpy::CHECK_CONFIRMATION_RESULT_PROVIDER_ERR : {
        if (context->get_CHK_CNF_reason() != IStateTyp::WAIT_FOR_ROUTING_INFO) {
            return false;
        }
        //SET RP_CAUSE: system failure
        //SEND SC_RP_ERROR_REQ
        context->send_SC_RP_ERROR_REQ("system failure");
        return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    //CHECK_INDICATION
    case IEventTpy::CHECK_INDICATION_RESULT_ERR : {
        //SET RP_IMSI
        //SET RP_MSISDN
        //SEND SC_RP_ERROR_REQ
        context->set_RP_IMSI();
        context->set_RP_MSISDN();
        context->send_SC_RP_ERROR_REQ();
        return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::CHECK_INDICATION_RESULT_OK : {
        if (context->is_ErrorFromHLR()) {
            //SET RP_IMSI
            //SET RP_MSISDN
            //SEND SC_RP_ERROR_REQ
            context->set_RP_IMSI();
            context->set_RP_MSISDN();
            context->send_SC_RP_ERROR_REQ();
            return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
        }
        if (context->is_RoutingInfoReceived()) {
            IState* state = StateHolder::getState(IStateTyp::MT_SM_DELIVERY_ATTEMPT_GMSC);
            if (NULL == state) {
                return false;
            }
            if (!context->pushState(state)) {
                return false;
            }
            return context->getCurrentState()->init(context);
        }
        //SEND SC_RP_ERROR_REQ
        context->send_SC_RP_ERROR_REQ();
        return context->pushState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    default: {
        return false;
    }
    }
    return false;
}
