//
// Created by zxf on 2019/11/10.
//

#ifndef SERVER_KREACTOR_H
#define SERVER_KREACTOR_H

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <unordered_map>
#include "../EventHandler.h"
#include "ReactorImpl.h"
class KReactor : public ReactorImpl {
public:
    KReactor();
    virtual ~KReactor();

    int registerEventHandler(EVENT_TYPE type,EventHandler*handler) override ;

    int registerEventHandler(int socket, EVENT_TYPE type, EventHandler*handler)override ;

    int removeEventHandler(EVENT_TYPE type, EventHandler*handler) override ;

    int removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler) override ;

    int handlerEvent() override;

private:
    int open();
    void remove(int socket);
    void reference();

    void release();

    int kq_{0};

    std::unordered_map<int,EventHandler*> sockLists_;
    struct kevent ev_[2]{0};
    int count_{};
};


#endif //SERVER_KREACTOR_H
