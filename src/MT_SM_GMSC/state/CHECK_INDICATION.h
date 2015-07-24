/*
 * CHECK_INDICATION.h
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#ifndef CHECK_INDICATION_H_
#define CHECK_INDICATION_H_

#include "AllState.h"

class CHECK_INDICATION: public IState {
public:
    CHECK_INDICATION();

    virtual bool init(IContext* context);

    virtual bool handleEvent(IContext* context);
};



#endif /* CHECK_INDICATION_H_ */
