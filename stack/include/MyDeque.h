#pragma once

#ifndef _MYDEQUE_H_
#define _MYDEQUE_H_

template<typename T>
class MyDeque{
private:
    T* elements;   // 一个循环一维数组
    size_t capacity;   // 数组总容量
    size_t size;   // 元素数量
    size_t frontIdx;   // deque前端索引
    size_t backIdx;   // deque后端索引

public:
    MyDeque();
    ~MyDeque();
    void push_front(const T& val);
    void push_back(const T& val);
    void pop_front();
    void pop_back();
    T& operator[](int idx);
    T& back();
    size_t getSize() const;
    void clear();
    void printElements() const;

private:
    void resize();
};

#endif