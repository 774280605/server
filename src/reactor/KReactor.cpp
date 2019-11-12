//
// Created by zxf on 2019/11/10.
//

#include "KReactor.h"


KReactor::KReactor() {

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
    return 0;
}

int KReactor::removeEventHandler(EVENT_TYPE type, EventHandler*handler) {
    return 0;
}

int KReactor::removeEventHandler(int socket, EVENT_TYPE type, EventHandler*handler) {
    return 0;
}

int KReactor::handlerEvent() {
    struct kevent ev[10]={0 };
    while (true) {
        auto ret = kevent(kq_, ev_, 2, ev, 2, 0);
        if (ret == -1) {
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