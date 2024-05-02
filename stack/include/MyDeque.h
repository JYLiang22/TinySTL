#pragma once

#ifndef _MYDEQUE_H_
#define _MYDEQUE_H_

template<typename T>
class MyDeque{
private:
    T* elements;   // һ��ѭ��һά����
    size_t capacity;   // ����������
    size_t size;   // Ԫ������
    size_t frontIdx;   // dequeǰ������
    size_t backIdx;   // deque�������

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