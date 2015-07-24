/*
 * WAIT_FOR_OPEN_CNF.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */


#include "AllState.h"

WAIT_FOR_OPEN_CNF::WAIT_FOR_OPEN_CNF() {
}

bool WAIT_FOR_OPEN_CNF::handleEvent(IContext* context) {
    if (NULL == context) {
        return NULL;
    }
    IEventTpy::EVENT_TYPE event_type = context->getEventType();
    switch (event_type) {
    case IEventTpy::MAP_NOTICE_IND : {
        //SEDN MAP_CLOSE_REQ
        context->send_MAP_CLOSE_REQ();
        return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_ERR, context);
    }
    case IEventTpy::MAP_U_ABORT_IND:
    case IEventTpy::MAP_P_ABORT_IND: {
        return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_ERR, context);
    }
    case IEventTpy::MAP_OPEN_CNF : {
        if (context->isDialogueAccepted()) {
            return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_OK, context);
        }
        switch (context->getRefuseReason()) {
        case IContext::AC_NOT_SUPPORT: {
            if (context->is_VersionLowThenSelf()) {
                return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_V1, context);
            }
            return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_ERR, context);
        }
        case IContext::POTENTAIL_VERSION_INCOMPATIBILITY: {
            return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_V1, context);
        }
        default: {
            return reportMacDefResult(IEventTpy::OPEN_CNF_RESULT_ERR, context);
        }
        }
        return false;
    }
    default : {
        return false;
    }
    }
    return false;
}
