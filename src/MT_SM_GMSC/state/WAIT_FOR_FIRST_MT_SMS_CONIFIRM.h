/*
 * WAIT_FOR_FIRST_MT_SMS_CONIFIRM.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_FIRST_MT_SMS_CONIFIRM_H_
#define WAIT_FOR_FIRST_MT_SMS_CONIFIRM_H_

#include "AllState.h"

class WAIT_FOR_FIRST_MT_SMS_CONIFIRM: public IState {
public:
    WAIT_FOR_FIRST_MT_SMS_CONIFIRM();

    virtual bool handleEvent(IContext* context);

};



#endif /* WAIT_FOR_FIRST_MT_SMS_CONIFIRM_H_ */
