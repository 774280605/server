//
// Created by zxf on 2019/11/21.
//

#ifndef SERVER_MQ_SERVANT_H
#define SERVER_MQ_SERVANT_H

#include <queue>
#include <string>

class Message{
public:
    Message(std::string msg);

    std::string msg_;
};


class MQ_Servant {
public:
    MQ_Servant(int mq_size);
    ~MQ_Servant();

    void put(const Message &msg);
    Message get();

    bool full()const;

    bool empty()const ;

private:
    std::queue<Message> queue_;
};



#endif //SERVER_MQ_SERVANT_H
