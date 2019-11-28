//
// Created by Demon on 2019/11/28.
//

#include "DemuxTable.h"

DemuxTable::Tuple *DemuxTable::getTuple(int fd) {
    auto it = table_.find(fd);
    if (it != table_.end()) {
        return &(it->second);
    }
    return nullptr;
}

void DemuxTable::addTuple(int fd, DemuxTable::Tuple tuple) {
    auto it = table_.find(fd);
    if (it != table_.end()) {
        it->second.eventType_|=tuple.eventType_;
    } else
        table_[fd]=tuple;

}

void DemuxTable::remove(int fd, int eventType) {
    auto it = table_.find(fd);
    if (it != table_.end()) {
        if (it->second.eventType_ == eventType) {
            table_.erase(it);
        } else{
            it->second.eventType_ &= (~eventType);
        }
    }

}

void DemuxTable::convert_to_fd_set(fd_set &readSet, fd_set &writeSet) {
    for (auto it = table_.begin();
         it != table_.end();
         ++it) {
        if ((it->second.eventType_ & EVENT_READ) == EVENT_READ) {
            FD_SET(it->first,&readSet);
        }
        if ((it->second.eventType_ & EVENT_WRITE) == EVENT_WRITE) {
            FD_SET(it->first,&writeSet);
        }
    }
}
