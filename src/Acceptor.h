//
// Created by zxf on 2019/11/12.
//

#ifndef SERVER_ACCEPTOR_H
#define SERVER_ACCEPTOR_H

#include "EventHandler.h"
#include"reactor/KReactor.h"
class Acceptor: public EventHandler {
public:
    Acceptor(KReactor *reactor);
    virtual ~Acceptor();

    int handleReadEvent(int fd) override;

    int handleWriteEvent(int fd) override;

private:
    void open();

    int socket_{0};

    KReactor*reactor_{nullptr};
};


#endif //SERVER_ACCEPTOR_H
