/*
 * REPORT_SM_DELIVERY_STAT_GMSC.h
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#ifndef REPORT_SM_DELIVERY_STAT_GMSC_H_
#define REPORT_SM_DELIVERY_STAT_GMSC_H_

#include "AllState.h"

class REPORT_SM_DELIVERY_STAT_GMSC: public IState {
public:
    REPORT_SM_DELIVERY_STAT_GMSC();

    virtual bool init(IContext* context);

    virtual bool handleEvent(IContext* context);

    virtual bool handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context);

};



#endif /* REPORT_SM_DELIVERY_STAT_GMSC_H_ */
