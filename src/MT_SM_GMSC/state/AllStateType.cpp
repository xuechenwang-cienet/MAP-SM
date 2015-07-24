/*
 * AllStateType.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#include "AllStateType.h"

namespace IStateTyp {

std::string getIStateTypStr(STATE_TYPE type) {
    switch (type) {
    case CHECK_CONFIRMATION :
        return "CHECK_CONFIRMATION";
    case CHECK_INDICATION :
        return "CHECK_INDICATION";
    case MT_SM_DELIVERY_ATTEMPT_GMSC :
        return "MT_SM_DELIVERY_ATTEMPT_GMSC";
    case MT_SM_GMSC :
        return "MT_SM_GMSC";
    case RECEIVE_OPEN_CNF :
        return "RECEIVE_OPEN_CNF";
    case REPORT_SM_DELIVERY_STAT_GMSC :
        return "REPORT_SM_DELIVERY_STAT_GMSC";
    case ST_NULL :
        return "ST_NULL";
    case WAIT_FOR_FIRST_MT_SMS_CONIFIRM :
        return "WAIT_FOR_FIRST_MT_SMS_CONIFIRM";
    case WAIT_FOR_INFORM_SC :
        return "WAIT_FOR_INFORM_SC";
    case WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY :
        return "WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY";
    case WAIT_FOR_OPEN_CNF :
        return "WAIT_FOR_OPEN_CNF";
    case WAIT_FOR_ROUTING_INFO :
        return "WAIT_FOR_ROUTING_INFO";
    case MT_SM_TRANSFER_MSC :
        return "MT_SM_TRANSFER_MSC";
    case WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM :
        return "WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM";
    case STATE_TYPE_MAX :
        return "STATE_TYPE_MAX";
    }
    return "";
}

}
