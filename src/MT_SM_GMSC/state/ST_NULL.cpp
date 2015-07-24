/*
 * ST_NULL.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#include "AllState.h"

ST_NULL::ST_NULL() {

};

bool ST_NULL::handleEvent(IContext* context) {
    if (NULL == context || IEventTpy::SC_RP_MT_DATA_IND != context->getEventType() ) {
        return NULL;
    }
    //SEDN MAP_OPEN_REQ
    //SEND MAP_SEND_ROUTING_INFO_FOR_SM_REQ
    //SEND MAP_DELIMITER_REQ
    context->send_MAP_OPEN_REQ();
    context->send_MAP_SEND_ROUTING_INFO_FOR_SM_REQ();
    context->send_MAP_DELIMITER_REQ();

    bool changeState = context->changeState(StateHolder::getState(IStateTyp::RECEIVE_OPEN_CNF));
    return (changeState && context->getCurrentState()->init(context));
}
