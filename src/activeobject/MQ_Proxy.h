//
// Created by zxf on 2019/11/24.
//

#ifndef SERVER_MQ_PROXY_H
#define SERVER_MQ_PROXY_H

#include "MQ_Servant.h"
#include "MQ_Scheduler.h"
class MQ_Proxy {
public:
    MQ_Proxy();
    ~MQ_Proxy();

    void put(Message &msg);

private:
    MQ_Servant servant_;
    MQ_Scheduler scheduler_;
};


#endif //SERVER_MQ_PROXY_H
