/*
 * WAIT_FOR_OPEN_CNF.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_OPEN_CNF_H_
#define WAIT_FOR_OPEN_CNF_H_

#include "AllState.h"

class WAIT_FOR_OPEN_CNF: public IState {
public:

    WAIT_FOR_OPEN_CNF();

    virtual bool handleEvent(IContext* context);

};



#endif /* WAIT_FOR_OPEN_CNF_H_ */
