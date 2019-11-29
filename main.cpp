#include <iostream>
#include "src/Acceptor.h"
#include "src/queue/ZXF_Queue.h"
#include "src/reactor/SelectReactorImpl.h"
#ifdef WIN32
#include <winsock2.h>
#endif

void testZXFQueue(){
    ZXF_Queue queue;

    for (int i = 0; i < 10; ++i) {
        auto value = new int(i);
        queue.put(value);
    }

    for (int j = 0; j < 10; ++j) {
        int* value = (int*)queue.pop();
        printf("%d\n",*value);
    }

}



int main() {
    Reactor* reactor=nullptr;
#ifdef WIN32
    WSADATA data;
    WSAStartup(0x0202,&data);

    reactor = new Reactor(new SelectReactorImpl);
#else
    reactor = new Reactor(new KReactor);

#endif

    testZXFQueue();


    auto acceptor= new Acceptor(reactor);
    while(true){
        auto result = reactor->handlerEvent();
        if (result < 0) {
            break;
        }
    }


    delete (reactor);

#ifdef  WIN32
    WSACleanup();
#endif

    return 0;
}