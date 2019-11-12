//
// Created by zxf on 2019/11/12.
//

#ifndef SERVER_REACTOR_H
#define SERVER_REACTOR_H

#include "../EventHandler.h"

enum EVENT_TYPE{
    EVENT_READ=0x01,
    EVENT_WRITE=0x02,
    EVENT_ACCEPT=0x04,

};

class Reactor {
public:
    Reactor()=default;
    virtual ~Reactor()=default;

    virtual int registerEventHandler(EVENT_TYPE type,EventHandler*handler)=0;

    virtual int registerEventHandler(int socket, EVENT_TYPE type, EventHandler*handler)=0;

    virtual int removeEventHandler(EVENT_TYPE type, EventHandler*handler)=0;

    virtual int removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler)=0;

    virtual int handlerEvent()=0;

};


#endif //SERVER_REACTOR_H
