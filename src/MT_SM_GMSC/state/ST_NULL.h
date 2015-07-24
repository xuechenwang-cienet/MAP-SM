/*
 * ST_NULL.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef ST_NULL_H_
#define ST_NULL_H_

#include "AllState.h"

class ST_NULL: public IState {
public:
    ST_NULL();

    virtual bool handleEvent(IContext* context);

};



#endif /* ST_NULL_H_ */
