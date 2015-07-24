/*
 * WAIT_FOR_INFORM_SC.h
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#ifndef WAIT_FOR_INFORM_SC_H_
#define WAIT_FOR_INFORM_SC_H_

class WAIT_FOR_INFORM_SC: public IState {
public:

    WAIT_FOR_INFORM_SC();

    virtual bool handleEvent(IContext* context);

};



#endif /* WAIT_FOR_INFORM_SC_H_ */
