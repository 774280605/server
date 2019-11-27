//
// Created by zxf on 2019/11/27.
//

#include <cstdlib>
#include "ZXF_Queue.h"

ZXF_Queue::ZXF_Queue() {

}

ZXF_Queue::~ZXF_Queue() {

}

void ZXF_Queue::init() {
    this->lists_ = (void **) malloc(this->maxSize_ * sizeof(void *));
    this->index_=0;
}

void *ZXF_Queue::pop() {
    if (isEmpty()) {
        return nullptr;
    }
    void*ret= lists_[index_++];
    index_%=maxSize_;
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
    lists_[index_++]=data;
    index_%=maxSize_;
    ++size_;
}
