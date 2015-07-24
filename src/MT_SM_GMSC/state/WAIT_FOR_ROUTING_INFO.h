/*
 * WAIT_FOR_ROUTING_INFO.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_ROUTING_INFO_H_
#define WAIT_FOR_ROUTING_INFO_H_

//TODO

#include "AllState.h"

class WAIT_FOR_ROUTING_INFO : public IState {
public:
    WAIT_FOR_ROUTING_INFO();

    virtual bool handleEvent(IContext* context);
};





#endif /* WAIT_FOR_ROUTING_INFO_H_ */
