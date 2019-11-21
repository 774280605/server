//
// Created by zxf on 2019/11/10.
//

#include "KReactor.h"
#include <sys/errno.h>

KReactor::KReactor() {
    open();
}

KReactor::~KReactor() {

}

int KReactor::registerEventHandler(EVENT_TYPE type, EventHandler*handler) {

    return 0;
}

int KReactor::registerEventHandler(int socket, EVENT_TYPE type, EventHandler*handler) {
    auto opt=0;
    if (type & EVENT_READ)
        opt|= EVFILT_READ;
    if(type&EVENT_WRITE)
        opt|=EVFILT_WRITE;

    EV_SET(&ev_[0],socket,opt,EV_ADD|EV_ENABLE,0,0,0);
    kevent(kq_,&ev_[0],1, nullptr,0, nullptr);
    sockLists_[socket]=handler;

    this->reference();

    return 0;
}

int KReactor::removeEventHandler(EVENT_TYPE type, EventHandler*handler) {
    return 0;
}

int KReactor::removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler) {
    auto opt=0;
    if (type & EVENT_READ)
        opt|= EVFILT_READ;
    if(type&EVENT_WRITE)
        opt|=EVFILT_WRITE;

    EV_SET(&ev_[0],socket,opt,EV_DELETE,0,0,0);
    kevent(kq_,&ev_[0],1, nullptr,0, nullptr);
    this->remove(socket);
    this->release();

    return 0;
}

int KReactor::handlerEvent() {
    struct kevent ev[10]={0 };

    while (true) {
        auto ret = kevent(kq_, nullptr, 0, ev, 10, NULL);
        if (ret == -1 && errno!= EINTR) {
            break;
        } else if(ret>0){
            for (int i = 0; i < ret; ++i) {
                if(ev[i].flags&EVFILT_READ){

                    int ident= ev[i].ident;
                    auto obj= this->sockLists_[ident];
                    obj->handleReadEvent(ident);

                }else if(ev[i].flags&EVFILT_WRITE){

                    int ident= ev[i].ident;
                    auto obj= this->sockLists_[ident];
                    obj->handleWriteEvent(ident);

                }


            }//for
        }//else if
    }
    return 0;
}

int KReactor::open() {
    kq_ = kqueue();
    if(kq_<0)
        return -1;

    return 0;
}

void KReactor::remove(int socket) {
    auto item = sockLists_.find(socket);
    if (item != sockLists_.end()) {
        sockLists_.erase(item);
    }
}

void KReactor::reference() {
    ++count_;
}

void KReactor::release() {
    --count_;
}
