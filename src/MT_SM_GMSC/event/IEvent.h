/*
 * IEvent.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef IEVENT_H_
#define IEVENT_H_

#include "AllEventType.h"

class IEvent {
public:
    IEvent(IEventTpy::EVENT_TYPE event_type):
        m_event_type(event_type) {
    }

    virtual ~IEvent(){};

    virtual char* getRAWData(int & length) {
        length = 0;
        return NULL;
    }

    virtual IEventTpy::EVENT_TYPE getEventType() {
        return m_event_type;
    }

private:
    IEventTpy::EVENT_TYPE m_event_type;
};

#endif /* IEVENT_H_ */
