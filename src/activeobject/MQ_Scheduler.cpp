//
// Created by zxf on 2019/11/24.
//

#include "MQ_Scheduler.h"

void MQ_Scheduler::svc_run(MQ_Scheduler *scheduler) {
    scheduler->dispatch();

}

void MQ_Scheduler::dispatch() {
    for (;;){
        auto mr = activationQueue_.remove(nullptr);
        if (mr->can_run()) {
            mr->call();
        }else   {
            break;
        }

    }
}

void MQ_Scheduler::insert(Method_Request *methodRequest) {

}

MQ_Scheduler::MQ_Scheduler() {
    thread_ = std::thread(svc_run, this);

}
