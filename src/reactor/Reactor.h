//
// Created by zxf on 2019/11/10.
//

#ifndef SERVER_REACTOR_H
#define SERVER_REACTOR_H

#include <unordered_map>
enum EVENT_TYPE{
    EVENT_READ=0x01,
    EVENT_WRITE=0x02,
    EVENT_ACCEPT=0x04,

};






template <typename SOCKET_OBJ>
class Reactor {
public:
    Reactor();
    virtual ~Reactor();
    int registerEventHandler(EVENT_TYPE type,SOCKET_OBJ obj);

    int registerEventHandler(int socket, EVENT_TYPE type, SOCKET_OBJ obj);

    int removeEventHandler(EVENT_TYPE type, SOCKET_OBJ obj);

    int removeEventHandler(int socket, EVENT_TYPE type, SOCKET_OBJ obj);

    int handlerEvent();

private:
    std::unordered_map<int,SOCKET_OBJ> sockLists_;

};

template<typename SOCKET_OBJ>
Reactor<SOCKET_OBJ>::Reactor() {

}

template<typename SOCKET_OBJ>
Reactor<SOCKET_OBJ>::~Reactor() {

}

template<typename SOCKET_OBJ>
int Reactor<SOCKET_OBJ>::registerEventHandler(EVENT_TYPE type, SOCKET_OBJ obj) {

    return 0;
}

template<typename SOCKET_OBJ>
int Reactor<SOCKET_OBJ>::registerEventHandler(int socket, EVENT_TYPE type, SOCKET_OBJ obj) {
    return 0;
}

template<typename SOCKET_OBJ>
int Reactor<SOCKET_OBJ>::removeEventHandler(EVENT_TYPE type, SOCKET_OBJ obj) {
    return 0;
}

template<typename SOCKET_OBJ>
int Reactor<SOCKET_OBJ>::removeEventHandler(int socket, EVENT_TYPE type, SOCKET_OBJ obj) {
    return 0;
}

template<typename SOCKET_OBJ>
int Reactor<SOCKET_OBJ>::handlerEvent() {
    return 0;
}


#endif //SERVER_REACTOR_H
