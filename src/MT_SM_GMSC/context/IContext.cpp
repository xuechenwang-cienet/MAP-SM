/*
 * IContext.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#include "AllState.h"
#include "IContext.h"

#include <iostream>

IContext::IContext():
    m_event(NULL),
    m_chk_cnf_reason(IStateTyp::MT_SM_GMSC) {

};

IContext::~IContext() {

};

bool IContext::init() {
    return pushState(StateHolder::getState(IStateTyp::MT_SM_GMSC));
}

IEventTpy::EVENT_TYPE IContext::getEventType() {
    return m_event->getEventType();
}

    //should has a event queue, and invoke handleEvent one by one.

bool IContext::handleEvent(IEvent* event) {
    //Need a lock here
    std::cout << "IContext::handleEvent [" << IEventTpy::getEventTypeStr(event->getEventType()) << "]" << std::endl;
    m_event = event;
    bool ret = getCurrentState()->handleEvent(this);
    std::cout << "IContext::handleEvent Finish" << std::endl;
    return ret;
}

IState* IContext::getCurrentState() {
    if (0 == m_state_tack.size()) {
        return NULL;
    }
    return m_state_tack.top();
}

bool IContext::pushState(IState* state) {
    m_state_tack.push(state);
    return true;
}

bool IContext::changeState(IState* state) {
    return (popState() && pushState(state));
}

bool IContext::popState(IState* & state) {
    if (0 == m_state_tack.size()) {
        return false;
    }
    state = m_state_tack.top();
    m_state_tack.pop();
    return true;
}

bool IContext::popState() {
    if (0 == m_state_tack.size()) {
        return false;
    }
    m_state_tack.pop();
    return true;
}


