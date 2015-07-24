/*
 * AllEventType.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#include "AllEventType.h"

namespace IEventTpy {

std::string getEventTypeStr(EVENT_TYPE type) {
    switch (type) {
    case SC_RP_MT_DATA_IND :
        return "SC_RP_MT_DATA_IND";
    case MAP_NOTICE_IND :
        return "MAP_NOTICE_IND";
    case MAP_U_ABORT_IND :
        return "MAP_U_ABORT_IND";
    case MAP_P_ABORT_IND :
        return "MAP_P_ABORT_IND";
    case MAP_OPEN_CNF :
        return "MAP_OPEN_CNF";
    case MAP_CLOSE_IND :
        return "MAP_CLOSE_IND";
    case MAP_MT_FORWARD_SHORT_MESSAGE_CNF :
        return "MAP_MT_FORWARD_SHORT_MESSAGE_CNF";
    case SC_ABORT_IND :
        return "SC_ABORT_IND";
    case MAP_SEND_ROUTING_INFO_FOR_SM_CNF :
        return "MAP_SEND_ROUTING_INFO_FOR_SM_CNF";
    case MAP_INFORM_SERVICE_CENTER_IND :
        return "MAP_INFORM_SERVICE_CENTER_IND";
    case EVENT_TYPE_MAX :
        return "EVENT_TYPE_MAX";
    }
    return "";
}

}
