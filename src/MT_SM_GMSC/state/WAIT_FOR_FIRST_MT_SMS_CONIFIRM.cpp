/*
 * WAIT_FOR_FIRST_MT_SMS_CONIFIRM.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#include "AllState.h"

WAIT_FOR_FIRST_MT_SMS_CONIFIRM::WAIT_FOR_FIRST_MT_SMS_CONIFIRM() {

}

bool WAIT_FOR_FIRST_MT_SMS_CONIFIRM::handleEvent(IContext* context) {
    if (NULL == context || IEventTpy::MAP_MT_FORWARD_SHORT_MESSAGE_CNF != context->getEventType()) {
        return false;
    }
    if (!context->set_CHK_CNF_reason(IStateTyp::WAIT_FOR_FIRST_MT_SMS_CONIFIRM)) {
        return false;
    }
    IState* state = StateHolder::getState(IStateTyp::CHECK_CONFIRMATION);
    if (NULL == state) {
        return false;
    }
    if (context->changeState(state)) {
        return false;
    }
    return context->getCurrentState()->init(context);
}
