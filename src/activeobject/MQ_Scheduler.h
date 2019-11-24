//
// Created by zxf on 2019/11/24.
//

#ifndef SERVER_MQ_SCHEDULER_H
#define SERVER_MQ_SCHEDULER_H


#include <thread>
#include "Activation_Queue.h"

class MQ_Scheduler {
public:
    MQ_Scheduler();
    ~MQ_Scheduler();

    void insert(Method_Request *methodRequest);
    virtual void dispatch();
private:
    Activation_Queue activationQueue_;
    static void svc_run(MQ_Scheduler*scheduler);
    std::thread thread_;
};


#endif //SERVER_MQ_SCHEDULER_H
