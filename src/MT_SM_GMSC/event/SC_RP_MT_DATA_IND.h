/*
 * SC_RP_MT_DATA_IND.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef SC_RP_MT_DATA_IND_H_
#define SC_RP_MT_DATA_IND_H_

#include "IEvent.h"

class SC_RP_MT_DATA_IND : public IEvent {
public:
    SC_RP_MT_DATA_IND():
        IEvent(IEventTpy::SC_RP_MT_DATA_IND) {
    };

    virtual ~SC_RP_MT_DATA_IND() {};
};


#endif /* SC_RP_MT_DATA_IND_H_ */
