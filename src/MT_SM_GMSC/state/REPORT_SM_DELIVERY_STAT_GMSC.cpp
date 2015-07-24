/*
 * REPORT_SM_DELIVERY_STAT_GMSC.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#include "AllState.h"

REPORT_SM_DELIVERY_STAT_GMSC::REPORT_SM_DELIVERY_STAT_GMSC() {

}

bool REPORT_SM_DELIVERY_STAT_GMSC::init(IContext* context) {
    if (NULL == context) {
        return false;
    }
    context->send_MAP_OPEN_REQ();
    context->send_MAP_REPORT_SM_DELIVERY_STATUS_REQ();
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

bool REPORT_SM_DELIVERY_STAT_GMSC::handleEvent(IContext* context) {

    return false;
}

bool REPORT_SM_DELIVERY_STAT_GMSC::handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
    if (NULL == context) {
        return false;
    }
    if (this != context->getCurrentState()) {
        return false;
    }
    switch (ret) {
    //OPEN_CNF_RESULT
    case IEventTpy::OPEN_CNF_RESULT_V1 : {
        //TODO omit
        return false;
    }
    case IEventTpy::OPEN_CNF_RESULT_Vr : {
        //TODO omit
        return false;
    }
    case IEventTpy::OPEN_CNF_RESULT_OK : {
        return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_HLR_R_RESPONSE));
    }
    case IEventTpy::OPEN_CNF_RESULT_ERR : {
        reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_PROVIDER_ERR, context);;
    }
    default: {
        return false;
    }
    }
    return false;
}
