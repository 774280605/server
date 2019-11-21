//
// Created by zxf on 2019/11/12.
//

#include "Session.h"
#include <sys/socket.h>
int Session::handleReadEvent(int fd) {
    char buffer[1024] = {0};
    auto bytes = recv(fd, buffer, 1024, 0);
    if(bytes>0)
        printf(buffer);
    else{
        reactor_->removeEventHandler(this->socket_, EVENT_READ, this);
        delete this;
    }

    return 0;
}

int Session::handleWriteEvent(int fd) {
    return 0;
}

Session::Session(int socket, KReactor *reactor) : socket_(socket), reactor_(reactor) {
    reactor_->registerEventHandler(socket_,EVENT_READ,this);
}

Session::~Session() {

}
