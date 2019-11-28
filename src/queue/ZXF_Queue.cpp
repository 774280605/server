//
// Created by zxf on 2019/11/27.
//

#include <cstdlib>
#include "ZXF_Queue.h"

ZXF_Queue::ZXF_Queue() {
    init();
}

ZXF_Queue::~ZXF_Queue() {

    free(this->lists_);
}

void ZXF_Queue::init() {
    this->lists_ = (void **) malloc(this->maxSize_ * sizeof(void *));
}

void *ZXF_Queue::pop() {
    if (isEmpty()) {
        return nullptr;
    }
    void*ret= lists_[readIndex_++];
    readIndex_%=maxSize_;
    --size_;
    return ret;
}

bool ZXF_Queue::isEmpty() {
    return size_ == 0;
}

bool ZXF_Queue::isFull() {
    return size_ == maxSize_;
}

void ZXF_Queue::put(void *data) {
    if(isFull())
        return;
    lists_[writeIndex_++]=data;
    writeIndex_%=maxSize_;
    ++size_;
}
