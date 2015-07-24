/*
 * WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#include "AllState.h"

WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY::WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY() {

}

bool WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY::handleEvent(IContext* context) {
    if (NULL == context || IEventTpy::SC_RP_MT_DATA_IND != context->getEventType()) {
        return false;
    }
    context->send_MAP_MT_FORWARD_SHORT_MESSAGE_REQ();
    context->send_MAP_DELIMITER_REQ();
    return context->changeState(StateHolder::getState(IStateTyp::WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM));
}
