//
// Created by zxf on 2019/11/24.
//

#include "MQ_Proxy.h"

void MQ_Proxy::put(Message &msg) {
    auto mr = new Get(&servant_);
    scheduler_.insert(mr);

}
