/*
 * WAIT_FOR_ROUTING_INFO.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#include "AllState.h"

WAIT_FOR_ROUTING_INFO::WAIT_FOR_ROUTING_INFO() {

}

bool WAIT_FOR_ROUTING_INFO::handleEvent(IContext* context) {
    if (NULL == context) {
        return false;
    }
    IEventTpy::EVENT_TYPE event_type =  context->getEventType();
    switch (event_type) {
    case IEventTpy::SC_ABORT_IND : {
        //SEND MAP_U_ABORT_REQ
        context->send_MAP_U_ABORT_REQ();
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::MAP_SEND_ROUTING_INFO_FOR_SM_CNF : {
        if (!context->set_CHK_CNF_reason(IStateTyp::WAIT_FOR_ROUTING_INFO)) {
            return false;
        }
        IState* state = StateHolder::getState(IStateTyp::CHECK_CONFIRMATION);
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
        //SET RP_CAUSE: system failure
        //SEND SC_RP_EROR_REQ
        context->send_MAP_CLOSE_REQ();
        context->send_SC_RP_ERROR_REQ("system failure");
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    case IEventTpy::MAP_U_ABORT_IND :
    case IEventTpy::MAP_P_ABORT_IND :
    case IEventTpy::MAP_CLOSE_IND : {
        //SET RP_CAUSE: system failure
        //SEND SC_RP_EROR_REQ
        context->send_SC_RP_ERROR_REQ("system failure");
        return context->changeState(StateHolder::getState(IStateTyp::ST_NULL));
    }
    default: {
        return false;
    }
    }
    return false;
}
