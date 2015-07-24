/*
 * WAIT_FOR_INFORM_SC.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#include "AllState.h"

WAIT_FOR_INFORM_SC::WAIT_FOR_INFORM_SC() {

}

bool WAIT_FOR_INFORM_SC::handleEvent(IContext* context) {
    if (NULL == context) {
        return false;
    }
    IEventTpy::EVENT_TYPE event_type =  context->getEventType();
    switch (event_type) {
    case IEventTpy::MAP_CLOSE_IND : {
        if (context->is_RoutingInfoReceived()) {
            return context->changeState(StateHolder::getState(IStateTyp::MT_SM_DELIVERY_ATTEMPT_GMSC));
        }
        //SEND SC_RP_ERROR_REQ
        context->send_SC_RP_ERROR_REQ();
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::MAP_INFORM_SERVICE_CENTER_IND : {
        IState* state = StateHolder::getState(IStateTyp::CHECK_INDICATION);
        if (NULL == state) {
            return false;
        }
        if (!context->changeState(state)) {
            return false;
        }
        if (!state->init(context)) {
            return false;
        }
        return true;
    }
    case IEventTpy::MAP_NOTICE_IND : {
        //SEND MAP_CLOSE_REQ
        //SET RP_IMSI
        //SET RP_MSISDN
        //SEND SC_RP_ERROR_REQ
        context->send_MAP_CLOSE_REQ();
        context->set_RP_IMSI();
        context->set_RP_MSISDN();
        context->send_SC_RP_ERROR_REQ();
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::SC_ABORT_IND : {
        //SEND MAP_U_ABORT_REQ
        context->send_MAP_U_ABORT_REQ();
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    default: {
        return false;
    }
    }
    return false;
}
