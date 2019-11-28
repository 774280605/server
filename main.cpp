#include <iostream>
#include "src/Acceptor.h"
#include "src/queue/ZXF_Queue.h"

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
#ifdef WIN32
#else
    auto reactor= new KReactor();
#endif

    testZXFQueue();


    auto acceptor= new Acceptor(nullptr);

    //reactor->handlerEvent();
    //delete (reactor);
    return 0;
}