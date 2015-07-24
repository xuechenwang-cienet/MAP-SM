/*
 * MAP_NOTICE_IND.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef MAP_NOTICE_IND_H_
#define MAP_NOTICE_IND_H_

#include "IEvent.h"

class MAP_NOTICE_IND : public IEvent {
public:
    MAP_NOTICE_IND():
        IEvent(IEventTpy::MAP_NOTICE_IND) {
    };

    virtual ~MAP_NOTICE_IND() {};
};




#endif /* MAP_NOTICE_IND_H_ */
