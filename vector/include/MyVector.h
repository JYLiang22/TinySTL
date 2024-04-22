#pragma once

#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

#include<iostream>

template<typename T>
class MyVector{
private:
    T *elements;   // ָ��̬�����ָ��
    size_t capacity;   // ���������
    size_t size;   // ������Ԫ�صĸ���

public:
    // ���졢�������������졢������ֵ����غ���
    MyVector();
    ~MyVector();
    MyVector(const MyVector &v);
    MyVector &operator=(const MyVector &v);

    void push_back(const T &value);
    size_t getSize() const;
    size_t getCapacity() const;
    T &operator[](size_t index);   // ���������е�Ԫ��
    const T &operator[](size_t index) const;   // const�汾�ķ��������е�Ԫ��
    void insert(size_t index, const T &value);
    void pop_back();
    void clear();
    T *begin();   // ʹ�õ�������������Ŀ�ʼλ��
    T *end();    // ʹ�õ�������������Ľ���λ��
    const T *begin() const;   // ʹ�õ�������������Ŀ�ʼλ�ã�const�汾��
    const T *end() const;   // ʹ�õ�������������Ľ���λ�ã�const�汾��
    void printElements() const;

private:
    void reserve(size_t newCapacity);   // ��չ��������
};

#endif