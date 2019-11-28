//
// Created by Demon on 2019/11/28.
//

#include "SelectReactorImpl.h"

SelectReactorImpl::SelectReactorImpl() {

}

SelectReactorImpl::~SelectReactorImpl() {

}

int SelectReactorImpl::registerEventHandler(EVENT_TYPE type, EventHandler *handler) {
    this->demuxTable_.addTuple(handler->get_handle(), DemuxTable::Tuple(handler,type));
    return 0;
}

int SelectReactorImpl::registerEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) {
    this->demuxTable_.addTuple(socket, DemuxTable::Tuple(handler,type));
    return 0;
}

int SelectReactorImpl::removeEventHandler(EVENT_TYPE type, EventHandler *handler) {
    this->demuxTable_.remove(handler->get_handle(), type);
    return 0;
}

int SelectReactorImpl::removeEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) {
    this->demuxTable_.remove(socket, type);
    return 0;
}

int SelectReactorImpl::handlerEvent() {
    fd_set readSet, writeSet;
    FD_ZERO(&readSet);
    FD_ZERO(&writeSet);

    demuxTable_.convert_to_fd_set(readSet, writeSet);

    int result = select(0, &readSet, &writeSet, nullptr, nullptr);
    if (result < 0) {
        return -1;
    }

    for (int k = demuxTable_.getMinfd(); k <=demuxTable_.getMaxfd() ; ++k) {
        auto tuple = demuxTable_.getTuple(k);
        if(tuple){
            if(FD_ISSET(k,&readSet)){
                tuple->handler_->handleReadEvent(k);
            }
            if (FD_ISSET(k, &writeSet)) {
                tuple->handler_->handleWriteEvent(k);
            }
        }

    }
    return 0;
}
