//
// Created by zxf on 2019/11/21.
//

#ifndef SERVER_MQ_SERVANT_H
#define SERVER_MQ_SERVANT_H

class Message{};


class MQ_Servant {
public:
    MQ_Servant(int mq_size);
    ~MQ_Servant();

    void put(const Message &msg);
    Message get();

    bool full()const;

    bool empty()const ;

};


#endif //SERVER_MQ_SERVANT_H
