/*
 * IState.h
 *
 *  Created on: Jul 15, 2015
 *      Author: git
 */

#ifndef ISTATE_H_
#define ISTATE_H_

#include <string>

#include "AllEvent.h"
#include "IContext.h"

class IState {
public:

    IState() {
    };

    virtual ~IState() {
    };

    virtual bool init(IContext* context) {
        return false;
    };

    virtual bool handleEvent(IContext* context) = 0;

    virtual bool handleMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
        return NULL;
    }

protected:

    virtual bool reportMacDefResult(IEventTpy::RETURN_RESULT ret, IContext* context) {
        context->popState();
        if (NULL == context->getCurrentState()) {
            return false;
        }
        return context->getCurrentState()->handleMacDefResult(ret, context);
    }

};


#endif /* ISTATE_H_ */
