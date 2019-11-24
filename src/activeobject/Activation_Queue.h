//
// Created by zxf on 2019/11/24.
//

#ifndef SERVER_ACTIVATION_QUEUE_H
#define SERVER_ACTIVATION_QUEUE_H

#include "Method_Request.h"

class Activation_Queue {
public:
    Activation_Queue()= default;
    ~Activation_Queue()= default;

    void insert(Method_Request *methodRequest);
    Method_Request* remove(Method_Request*methodRequest);

private:
    std::queue<Method_Request*> queue_;

};


#endif //SERVER_ACTIVATION_QUEUE_H
