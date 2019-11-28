//
// Created by zxf on 2019/11/27.
//

#ifndef SERVER_ZXF_QUEUE_H
#define SERVER_ZXF_QUEUE_H


class ZXF_Queue {
public:
    ZXF_Queue();
    ~ZXF_Queue();

    void *pop();

    void put(void *data);
    bool isEmpty();

    bool isFull();

private:
    void* *lists_{nullptr};

    int maxSize_{10};
    int readIndex_{};
    int writeIndex_{};
    int size_{};

    void init();


};


#endif //SERVER_ZXF_QUEUE_H
