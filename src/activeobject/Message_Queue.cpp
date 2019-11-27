//
// Created by zxf on 2019/11/27.
//

#include "Message_Queue.h"
#include "MQ_Servant.h"
Message_Queue::Message_Queue() {

}

Message_Queue::~Message_Queue() {

}

void Message_Queue::put(Message &message) {

}

Message Message_Queue::get() {
    return Message("zhangxiaofei");
}

bool Message_Queue::isFull() {
    return false;
}

bool Message_Queue::ifEmpty() {
    return false;
}
