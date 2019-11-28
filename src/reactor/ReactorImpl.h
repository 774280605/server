//
// Created by Demon on 2019/11/28.
//

#ifndef SERVER_REACTORIMPL_H
#define SERVER_REACTORIMPL_H

#include "../EventHandler.h"


class ReactorImpl {
public:
    ReactorImpl()= default;
    virtual ~ReactorImpl()= default;

    virtual int registerEventHandler(EVENT_TYPE type,EventHandler*handler)=0;

    virtual int registerEventHandler(int socket, EVENT_TYPE type, EventHandler*handler)=0;

    virtual int removeEventHandler(EVENT_TYPE type, EventHandler*handler)=0;

    virtual int removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler)=0;

    virtual int handlerEvent()=0;
};


#endif //SERVER_REACTORIMPL_H
