/*
 * main.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: git
 */

#include <ace/Synch.h>

#include "AllEvent.h"
#include "AllState.h"

using namespace std;

int testFunc(IContext* context, IEventTpy::EVENT_TYPE type) {
    IEvent event(type);
    if (!context->handleEvent(&event)) {
        return (int)type;
    }
    return -1;
}

int main() {

    StateHolder::initState();

    IContext* context = new IContext();
    context->init();

    testFunc(context, IEventTpy::SC_RP_MT_DATA_IND);
    testFunc(context, IEventTpy::MAP_OPEN_CNF);
    testFunc(context, IEventTpy::MAP_SEND_ROUTING_INFO_FOR_SM_CNF);

    testFunc(context, IEventTpy::MAP_INFORM_SERVICE_CENTER_IND);
    testFunc(context, IEventTpy::MAP_OPEN_CNF);

    return 0;
}

