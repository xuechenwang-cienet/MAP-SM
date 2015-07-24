/*
 * RECEIVE_OPEN_CNF.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */


#include "AllState.h"

RECEIVE_OPEN_CNF::RECEIVE_OPEN_CNF() {

}

bool RECEIVE_OPEN_CNF::init(IContext* context) {
    if (NULL == context) {
        return false;
    }
    return context->pushState(StateHolder::getState(IStateTyp::WAIT_FOR_OPEN_CNF));
}

bool RECEIVE_OPEN_CNF::handleEvent(IContext* context) {
    return false;
}

bool RECEIVE_OPEN_CNF::handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
    return reportMacDefResult(ret, context);
}
