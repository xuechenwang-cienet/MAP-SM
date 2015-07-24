/*
 * MT_SM_GMSC.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef MT_SM_GMSC_H_
#define MT_SM_GMSC_H_

#include "AllState.h"

class MT_SM_GMSC : public IState {
public:
    MT_SM_GMSC();

    virtual bool handleEvent(IContext* context);

    virtual bool handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context);

};



#endif /* MT_SM_GMSC_H_ */
