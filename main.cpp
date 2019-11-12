#include <iostream>
#include <sys/socket.h>
#include "src/Acceptor.h"
int main() {
    auto reactor= new KReactor();
    auto acceptor= new Acceptor(reactor);

    reactor->handlerEvent();
    delete (reactor);
    return 0;
}