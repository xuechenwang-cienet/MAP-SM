/*
 * StateHolder.h
 *
 *  Created on: Jul 16, 2015
 *      Author: git
 */

#ifndef STATEHOLDER_H_
#define STATEHOLDER_H_

#include <map>

#include "AllState.h"

class StateHolder {
public:
    static bool initState();
    static IState* getState(IStateTyp::STATE_TYPE type);
private:
    typedef std::map<IStateTyp::STATE_TYPE, IState*> StateMapTyp;
    static StateMapTyp m_state_map;
};



#endif /* STATEHOLDER_H_ */
