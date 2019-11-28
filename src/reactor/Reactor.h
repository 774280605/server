//
// Created by zxf on 2019/11/12.
//

#ifndef SERVER_REACTOR_H
#define SERVER_REACTOR_H

#include "../EventHandler.h"
#include "ReactorImpl.h"


class Reactor {
public:
    Reactor(ReactorImpl*reactor);
    virtual ~Reactor()=default;

    virtual int registerEventHandler(EVENT_TYPE type,EventHandler*handler);

    virtual int registerEventHandler(int socket, EVENT_TYPE type, EventHandler*handler);

    virtual int removeEventHandler(EVENT_TYPE type, EventHandler*handler);

    virtual int removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler);

    virtual int handlerEvent();

private:
    ReactorImpl*reactor_;
};


#endif //SERVER_REACTOR_H
