/*
 * CHECK_INDICATION.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#include "AllState.h"

CHECK_INDICATION::CHECK_INDICATION() {
}

bool CHECK_INDICATION::init(IContext* context) {
    if (NULL == context) {
        return false;
    }
    if (context->is_CHK_IND_DataMiss()) {
        //SET User Error: Data missing
        return reportMacDefResult(IEventTpy::CHECK_INDICATION_RESULT_ERR, context);
    }
    if (context->is_CHK_IND_UnexpData()) {
        //SET User Error: unexpected data and value
        return reportMacDefResult(IEventTpy::CHECK_INDICATION_RESULT_ERR, context);
    }
    if (context->is_CHK_IND_UnexpVaule()) {
        //SET User Error: unexpected data and value
        return reportMacDefResult(IEventTpy::CHECK_INDICATION_RESULT_ERR, context);
    }
    return reportMacDefResult(IEventTpy::CHECK_INDICATION_RESULT_OK, context);
}

bool CHECK_INDICATION::handleEvent(IContext* context) {
    return false;
}
