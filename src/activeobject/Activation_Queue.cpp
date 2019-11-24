//
// Created by zxf on 2019/11/24.
//

#include "Activation_Queue.h"

Method_Request* Activation_Queue::remove(Method_Request *methodRequest) {
    return queue_.front();
}

void Activation_Queue::insert(Method_Request *methodRequest) {
    queue_.push(methodRequest);
}
