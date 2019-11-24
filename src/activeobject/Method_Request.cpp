//
// Created by zxf on 2019/11/24.
//

#include <cstdio>
#include "Method_Request.h"

bool Get::can_run() const {
    return !servant_->empty();
}

void Get::call() {
    printf("Get::call()");
}
