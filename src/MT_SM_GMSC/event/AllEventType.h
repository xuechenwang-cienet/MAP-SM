/*
 * AllEventType.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef ALLEVENTTYPE_H_
#define ALLEVENTTYPE_H_

#include <string>

namespace IEventTpy {

    enum EVENT_TYPE {
        SC_RP_MT_DATA_IND,
        MAP_NOTICE_IND,
        MAP_U_ABORT_IND,
        MAP_P_ABORT_IND,
        MAP_OPEN_CNF,
        MAP_CLOSE_IND,
        MAP_MT_FORWARD_SHORT_MESSAGE_CNF,
        SC_ABORT_IND,
        MAP_SEND_ROUTING_INFO_FOR_SM_CNF,
        MAP_INFORM_SERVICE_CENTER_IND,
        EVENT_TYPE_MAX,
    };

    enum RETURN_RESULT {
        //OPEN_CNF_RESULT
        OPEN_CNF_RESULT_V1,
        OPEN_CNF_RESULT_Vr,
        OPEN_CNF_RESULT_OK,
        OPEN_CNF_RESULT_ERR,
        //MT_SM_DELIVERY_ATTEMPT_GMSC_RESULT {
        MT_SM_DLVRY_RESULT_FAIL,
        MT_SM_DLVRY_RESULT_PASS,
        MT_SM_DLVRY_RESULT_ABORT,
        //CHECK_CONFIRMATION
        CHECK_CONFIRMATION_RESULT_OK,
        CHECK_CONFIRMATION_RESULT_USER_ERR,
        CHECK_CONFIRMATION_RESULT_DATA_ERR,
        CHECK_CONFIRMATION_RESULT_PROVIDER_ERR,
        //CHECK_INDICATION
        CHECK_INDICATION_RESULT_OK,
        CHECK_INDICATION_RESULT_ERR,
        //REPORT_SM_DELIVERY_STAT_GMSC
        REPORT_SM_DELIVERY_STAT_GMSC_OK,
        REPORT_SM_DELIVERY_STAT_GMSC_ERR,
    };

    std::string getEventTypeStr(EVENT_TYPE type);

};


#endif /* ALLEVENTTYPE_H_ */