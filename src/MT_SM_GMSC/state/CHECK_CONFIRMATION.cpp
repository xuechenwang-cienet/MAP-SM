/*
 * CHECK_CONFIRMATION.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#include "AllState.h"

CHECK_CONFIRMATION::CHECK_CONFIRMATION() {

}

bool CHECK_CONFIRMATION::init(IContext* context) {
    if(context->is_ProviderError()) {
        //SEND MAP_CLOSE_REQ
        context->send_MAP_CLOSE_REQ();
        return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_PROVIDER_ERR, context);
    }
    if (context->is_CHK_CNF_UserErr()) {
        return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_USER_ERR, context);
    }
    if (context->is_CHK_CNF_DataMiss()) {
        return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_DATA_ERR, context);
    }
    if (context->is_CHK_CNF_UnexpData()) {
        return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_DATA_ERR, context);
    }
    if (context->is_CHK_CNF_UnexpVaule()) {
        return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_DATA_ERR, context);
    }
    return reportMacDefResult(IEventTpy::CHECK_CONFIRMATION_RESULT_OK, context);
}

bool CHECK_CONFIRMATION::handleEvent(IContext* context) {
    return false;
}
