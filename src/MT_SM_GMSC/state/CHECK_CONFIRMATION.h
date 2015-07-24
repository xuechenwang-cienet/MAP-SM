/*
 * CHECK_CONFIRMATION.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef CHECK_CONFIRMATION_H_
#define CHECK_CONFIRMATION_H_

#include "AllState.h"

class CHECK_CONFIRMATION: public IState {
public:
    CHECK_CONFIRMATION();

    virtual bool init(IContext* context);

    virtual bool handleEvent(IContext* context);
};



#endif /* CHECK_CONFIRMATION_H_ */
