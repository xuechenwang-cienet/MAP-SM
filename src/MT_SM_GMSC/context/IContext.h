/*
 * IContext.h
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#ifndef ICONTEXT_H_
#define ICONTEXT_H_

#include <stack>
#include <string>

#include "AllEvent.h"
#include "AllStateType.h"

class IState;

class IContext {
public:
    typedef std::stack<IState*> StateStackTyp;

    IContext();
    virtual ~IContext();

    virtual bool init();

    virtual IEventTpy::EVENT_TYPE getEventType();

    //should has a event queue, and invoke handleEvent one by one.

    bool handleEvent(IEvent* event);

    bool is_RoutingInfoReceived() {
        return true;
    }

    void send_SC_RP_ERROR_REQ(std::string RP_CAUSE) {

    }

    bool is_LMSIIncludedInRoutingInfo() {
        return true;
    }

    void set_DestinationReference(std::string ref) {

    }

    void set_SM_RP_DAL(std::string data) {

    }

    void set_RP_CAUSE(std::string cause) {

    }

    void set_RP_IMSI() {

    }

    void set_RP_MSISDN() {

    }

    void send_SC_RP_ERROR_REQ() {

    }

    bool is_ErrorFromHLR() {
        return false;
    }

    void send_MAP_OPEN_REQ() {

    }

    void send_MAP_SEND_ROUTING_INFO_FOR_SM_REQ() {

    }

    void send_MAP_DELIMITER_REQ() {

    }

    void send_MAP_CLOSE_REQ() {

    }

    bool isDialogueAccepted() {
        return true;
    }

    enum REFUSE_REASON {
        AC_NOT_SUPPORT,
        POTENTAIL_VERSION_INCOMPATIBILITY,
        REFUSE_REASON_ELSE,
    };

    REFUSE_REASON getRefuseReason() {
        return AC_NOT_SUPPORT;
    }

    bool is_VersionLowThenSelf () {
        return true;
    }

    void send_MAP_U_ABORT_REQ() {

    }

    void send_MAP_MT_FORWARD_SHORT_MESSAGE_REQ() {

    }

    bool is_ProviderError() {
        return false;
    }

    bool is_CHK_CNF_UserErr() {
        return false;
    }

    enum CHK_CNF_USERERR_CAUSE {
        UNIDENTIFIED_SUBSCRIBER,
        ABSENT_SUBSCRIBER,
        MS_MEMORY_CAPACITY_EXCEEDED,
        CHK_CNF_USERERR_CAUSE_ELSE,
    };

    CHK_CNF_USERERR_CAUSE get_CHK_CNF_UserErr_Cause() {
        return UNIDENTIFIED_SUBSCRIBER;
    }

    bool is_CHK_CNF_DataMiss() {
        return false;
    }

    bool is_CHK_CNF_UnexpData() {
        return false;
    }

    bool is_CHK_CNF_UnexpVaule() {
        return false;
    }

    bool is_CHK_IND_DataMiss() {
        return false;
    }

    bool is_CHK_IND_UnexpData() {
        return false;
    }

    bool is_CHK_IND_UnexpVaule() {
        return false;
    }

    bool is_ServingNodeGMSC() {
        return false;
    }

    bool is_MessageSegmentingNeeded() {
        return false;
    }

    bool is_TCAPHandshakeRequired() {
        return false;
    }

    bool is_SuccessfulDelivery() {
        return true;
    }

    bool set_CHK_CNF_reason(IStateTyp::STATE_TYPE type) {
        m_chk_cnf_reason = type;
        return true;
    }

    IStateTyp::STATE_TYPE get_CHK_CNF_reason() {
        return m_chk_cnf_reason;
    }

    bool is_MoreMessagesToSend() {
        return false;
    }

    void send_SC_RP_ACK_REQ() {

    }

    bool is_MCEForMNRFsetInHLR() {
        return true;
    }

    void set_RP_ERRPR() {

    }

    void send_MAP_REPORT_SM_DELIVERY_STATUS_REQ() {

    }
    /*
     *  State change func
     */

    bool popState();

    IState* getCurrentState();

    bool pushState(IState* state);

    bool changeState(IState* state);

    bool popState(IState* & state);

private:
    StateStackTyp m_state_tack;

    IEvent* m_event;

    IStateTyp::STATE_TYPE m_chk_cnf_reason;
};



#endif /* ICONTEXT_H_ */
