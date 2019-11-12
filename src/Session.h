//
// Created by zxf on 2019/11/12.
//

#ifndef SERVER_SESSION_H
#define SERVER_SESSION_H

#include "EventHandler.h"
#include "reactor/KReactor.h"
class Session :public EventHandler{
public:
    Session(int socket, KReactor *reactor);
    virtual ~Session();

    int handleReadEvent(int fd) override;

    int handleWriteEvent(int fd) override;

private:
    int socket_{0};
    KReactor*reactor_{nullptr};
};


#endif //SERVER_SESSION_H
