/*
 * RECEIVE_OPEN_CNF.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef RECEIVE_OPEN_CNF_H_
#define RECEIVE_OPEN_CNF_H_

#include "AllState.h"

class RECEIVE_OPEN_CNF: public IState {
public:
    RECEIVE_OPEN_CNF();

    virtual bool init(IContext* context);

    virtual bool handleEvent(IContext* context);

    virtual bool handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context);


};

#endif /* RECEIVE_OPEN_CNF_H_ */
