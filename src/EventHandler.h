//
// Created by zxf on 2019/11/11.
//

#ifndef SERVER_EVENTHANDLER_H
#define SERVER_EVENTHANDLER_H
enum EVENT_TYPE{
    EVENT_READ=0x01,
    EVENT_WRITE=0x02,
    EVENT_ACCEPT=0x04,

};

class EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    virtual int handleReadEvent(int fd);

    virtual int handleWriteEvent(int fd);

    virtual int get_handle();

};


#endif //SERVER_EVENTHANDLER_H
