//
// Created by zxf on 2019/11/24.
//

#ifndef SERVER_METHOD_REQUEST_H
#define SERVER_METHOD_REQUEST_H

#include "MQ_Servant.h"


class Method_Request {
public:
    Method_Request()= default;
    virtual ~Method_Request()= default;
    virtual bool can_run()const=0;
    virtual void call()=0;
};


class Get:public Method_Request{
public:
    Get(MQ_Servant*servant);
    virtual ~Get();

    bool can_run() const override;

    void call() override;


private:
    MQ_Servant*servant_;

};






#endif //SERVER_METHOD_REQUEST_H
