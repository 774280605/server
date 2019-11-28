//
// Created by Demon on 2019/11/28.
//

#ifndef SERVER_SELECTREACTORIMPL_H
#define SERVER_SELECTREACTORIMPL_H

#include "ReactorImpl.h"
#include "../DemuxTable.h"
class SelectReactorImpl :public ReactorImpl{
public:
    SelectReactorImpl();
    virtual ~SelectReactorImpl();

    int registerEventHandler(EVENT_TYPE type, EventHandler *handler) override;

    int registerEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) override;

    int removeEventHandler(EVENT_TYPE type, EventHandler *handler) override;

    int removeEventHandler(int socket, EVENT_TYPE type, EventHandler *handler) override;

    int handlerEvent() override;


private:
    DemuxTable demuxTable_;
};


#endif //SERVER_SELECTREACTORIMPL_H
