/*
 * StateHolder.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#include "AllState.h"

#include "iostream"

StateHolder::StateMapTyp StateHolder::m_state_map;

/*
CHECK_CONFIRMATION,
CHECK_INDICATION,
MT_SM_DELIVERY_ATTEMPT_GMSC,
MT_SM_GMSC,
RECEIVE_OPEN_CNF,
ST_NULL,
WAIT_FOR_FIRST_MT_SMS_CONIFIRM,
WAIT_FOR_INFORM_SC,
WAIT_FOR_OPEN_CNF,
WAIT_FOR_ROUTING_INFO,
*/

bool StateHolder::initState() {
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::CHECK_CONFIRMATION, new CHECK_CONFIRMATION()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::CHECK_INDICATION, new CHECK_INDICATION()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::MT_SM_DELIVERY_ATTEMPT_GMSC, new MT_SM_DELIVERY_ATTEMPT_GMSC()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::MT_SM_GMSC, new MT_SM_GMSC()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::RECEIVE_OPEN_CNF, new RECEIVE_OPEN_CNF()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::ST_NULL, new ST_NULL()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::WAIT_FOR_FIRST_MT_SMS_CONIFIRM, new WAIT_FOR_FIRST_MT_SMS_CONIFIRM()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::WAIT_FOR_INFORM_SC, new WAIT_FOR_INFORM_SC()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::WAIT_FOR_OPEN_CNF, new WAIT_FOR_OPEN_CNF()));
    m_state_map.insert(StateMapTyp::value_type(IStateTyp::WAIT_FOR_ROUTING_INFO, new WAIT_FOR_ROUTING_INFO()));
    return true;
}

IState* StateHolder::getState(IStateTyp::STATE_TYPE type) {
    StateMapTyp::iterator it = m_state_map.find(type);
    if (m_state_map.end() == it) {
        std::cout << "StateHolder::getState [" << IStateTyp::getIStateTypStr(type) << "] fail" << std::endl;
        return NULL;
    }
    std::cout << "StateHolder::getState [" << IStateTyp::getIStateTypStr(type) << "] success" << std::endl;
    return it->second;
}

