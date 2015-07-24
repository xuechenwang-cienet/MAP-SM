/*
 * WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM.h
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM_H_
#define WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM_H_

#include "AllState.h"

class WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM: public IState {
public:

    WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM();

    virtual bool handleEvent(IContext* context);

};



#endif /* WAIT_FOR_SUBSEQUENT_MT_SMS_CONFIRM_H_ */
