//
// Created by zxf on 2019/11/12.
//

#include "Acceptor.h"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include"Session.h"
int Acceptor::handleReadEvent(int fd) {
    struct sockaddr_in sin;
    auto len = sizeof(sin);
    auto accept_fd = accept(fd, (struct sockaddr*)&sin, (socklen_t*)&len);
    if(accept_fd==-1)
        return-1;
    auto session=new Session(accept_fd,this->reactor_);

    return 0;
}

int Acceptor::handleWriteEvent(int fd) {
    return 0;
}

Acceptor::Acceptor(KReactor *reactor): reactor_(reactor) {
    this->open();
}

Acceptor::~Acceptor() {

}

void Acceptor::open() {
    socket_=socket(AF_INET,SOCK_STREAM,0);
    if(socket_==-1)
        printf("socket_==-1\n");
    struct sockaddr_in sin;
    sin.sin_family=AF_INET;
    sin.sin_port = htons(9999);
    sin.sin_addr.s_addr=INADDR_ANY;
    if(bind(socket_,(struct sockaddr*)&sin,sizeof(sin))==-1){
        printf("bind error!\n");
        return;
    }

    if(listen(socket_,SOMAXCONN)==-1) {
        printf("listen error!\n");
        return;
    }

    reactor_->registerEventHandler(socket_, EVENT_READ, this);
}
