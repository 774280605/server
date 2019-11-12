//
// Created by zxf on 2019/11/11.
//

#ifndef SERVER_EVENTHANDLER_H
#define SERVER_EVENTHANDLER_H


class EventHandler {
public:
    EventHandler();
    virtual ~EventHandler();

    virtual int handleReadEvent(int fd);

    virtual int handleWriteEvent(int fd);


};


#endif //SERVER_EVENTHANDLER_H
