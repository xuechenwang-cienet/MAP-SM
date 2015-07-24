/*
 * WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY.h
 *
 *  Created on: Jul 20, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY_H_
#define WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY_H_

#include "AllState.h"

class WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY: public IState {
public:
    WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY();

    virtual bool handleEvent(IContext* context);

};



#endif /* WAIT_FOR_MORE_MESSAGE_REMOTE_DELIVERY_H_ */
