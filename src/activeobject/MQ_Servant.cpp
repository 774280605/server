//
// Created by zxf on 2019/11/21.
//

#include "MQ_Servant.h"



MQ_Servant::MQ_Servant(int mq_size) {

}

MQ_Servant::~MQ_Servant() {

}

void MQ_Servant::put(const Message &msg) {

}

Message MQ_Servant::get() {
    return queue_.front();
}

bool MQ_Servant::empty()const{
    return queue_.empty();
}

bool MQ_Servant::full() const {

    return queue_.empty();
}

Message::Message(std::string msg):msg_(msg) {

}
