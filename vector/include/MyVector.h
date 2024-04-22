#pragma once

#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

#include<iostream>

template<typename T>
class MyVector{
private:
    T *elements;   // 指向动态数组的指针
    size_t capacity;   // 数组的容量
    size_t size;   // 数组中元素的个数

public:
    // 构造、析构、拷贝构造、拷贝赋值等相关函数
    MyVector();
    ~MyVector();
    MyVector(const MyVector &v);
    MyVector &operator=(const MyVector &v);

    void push_back(const T &value);
    size_t getSize() const;
    size_t getCapacity() const;
    T &operator[](size_t index);   // 访问数组中的元素
    const T &operator[](size_t index) const;   // const版本的访问数组中的元素
    void insert(size_t index, const T &value);
    void pop_back();
    void clear();
    T *begin();   // 使用迭代器遍历数组的开始位置
    T *end();    // 使用迭代器遍历数组的结束位置
    const T *begin() const;   // 使用迭代器遍历数组的开始位置（const版本）
    const T *end() const;   // 使用迭代器遍历数组的结束位置（const版本）
    void printElements() const;

private:
    void reserve(size_t newCapacity);   // 拓展数组容量
};

#endif