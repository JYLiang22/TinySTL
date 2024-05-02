#pragma once

#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#include"MyDeque.h"

template<typename T, typename Container = MyDeque<T>>
class MyStack{
private:
    Container data;   // ʹ�õײ�����deque�洢ջ��Ԫ��

public:
    // MyStack();
    // ~MyStack();
    void push(const T &value);
    void pop();
    T &top();
    bool empty() const;
    size_t size() const;
    void clear();
};

#endif