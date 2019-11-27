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

private:
    void* *lists_{nullptr};

    int maxSize_{10};
    int index_{};
    int size_{};

    void init();

    bool isEmpty();

    bool isFull();
};


#endif //SERVER_ZXF_QUEUE_H
