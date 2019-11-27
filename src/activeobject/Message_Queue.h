//
// Created by zxf on 2019/11/27.
//

#ifndef SERVER_MESSAGE_QUEUE_H
#define SERVER_MESSAGE_QUEUE_H
#include<condition_variable>
#include <mutex>

class Message;

class Message_Queue {
public:
    Message_Queue();
    ~Message_Queue();

    void put(Message &message);

    Message get();

    bool isFull();
    bool ifEmpty();

private:
    std::condition_variable not_Empty_;
    std::condition_variable not_Full_;
    std::mutex mutex_;


};


#endif //SERVER_MESSAGE_QUEUE_H
