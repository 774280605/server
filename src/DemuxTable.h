//
// Created by Demon on 2019/11/28.
//

#ifndef SERVER_DEMUXTABLE_H
#define SERVER_DEMUXTABLE_H

#include "EventHandler.h"
#ifdef WIN32
#include "winsock2.h"
#endif

#include <map>

class DemuxTable {
public:
    class Tuple{
    public:
        EventHandler*handler_;
        int eventType_;

        Tuple(EventHandler*handler,int eventType):handler_(handler),eventType_(eventType){

        }
        Tuple(){
            eventType_=0;
            handler_=nullptr;
        }
        Tuple(const Tuple&tuple){
            this->handler_=tuple.handler_;
            this->eventType_=tuple.eventType_;
        }

        Tuple &operator=(const Tuple &tuple){
            this->eventType_=tuple.eventType_;
            this->handler_=tuple.handler_;
            return *this;
        }
    };

    Tuple *getTuple(int fd);
    void addTuple(int fd,Tuple tuple);
    void remove(int fd, int eventType);

    void convert_to_fd_set(fd_set& readSet,fd_set&writeSet);

    DemuxTable()= default;
    ~DemuxTable()= default;


private:
    std::map<int,Tuple> table_;
};


#endif //SERVER_DEMUXTABLE_H
