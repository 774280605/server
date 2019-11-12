//
// Created by zxf on 2019/11/12.
//

#include "Session.h"

int Session::handleReadEvent(int fd) {
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
