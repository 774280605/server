//
// Created by zxf on 2019/11/12.
//

#include "Reactor.h"

Reactor::Reactor(ReactorImpl *reactor):reactor_(reactor) {

}

int Reactor::registerEventHandler(EVENT_TYPE type, EventHandler *handler) {
    reactor_->registerEventHandler(type, handler);
    return 0;
}

int Reactor::registerEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) {
    reactor_->registerEventHandler(socket, type, handler);
    return 0;
}

int Reactor::removeEventHandler(EVENT_TYPE type, EventHandler *handler) {
    reactor_->removeEventHandler(type, handler);
    return 0;
}

int Reactor::removeEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) {
    reactor_->removeEventHandler(socket, type, handler);
    return 0;
}

int Reactor::handlerEvent() {
    reactor_->handlerEvent();
    return 0;
}
