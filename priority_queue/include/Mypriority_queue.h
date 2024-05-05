#ifndef _MYPRIORITY_QUEUE_H_
#define _MYPRIORITY_QUEUE_H_

#include<iostream>
#include<vector>

template<typename T, typename Container = std::vector<T>>
class Mypriority_queue{
private:
    Container data;

    void heapifyUp();   // �������������ϵ���Ԫ����ά��������
    void heapifyDown();   // �������������µ���Ԫ����ά��������

public:
    Mypriority_queue();
    Mypriority_queue(const Container &c);

    void push(const T &value);
    void pop();
    T &top();
    bool empty() const;
    size_t size() const;
};

#endif