#pragma once

#ifndef _MYVECTOR_OPTI_H_
#define _MYVECTOR_OPTI_H_

#include<iostream>

template<typename T>
class MyVector{
private:
    static std::allocator<T> alloc;   // allocates the elements

    // utility functions
    // used by members that add elements to the StrVec
    void chk_n_alloc();
    // to judge whether the capacity if satisfied the need
    void reserve(size_t n);

    // used by the copy constructor, assignment operator, and destructor
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();   // destroy the elements and free the space
    void reallocate();   // get more space and copy the existing elements
    void reallocate(size_t newcapacity);   // get more space and copy the existing elements
    T *elements;   // pointer to the first element in the array
    T *first_free;   // pointer to the first free element in the array
    T *cap;   // pointer to one past the end of the array

public:
    // copy control members
    MyVector();
    MyVector(const MyVector&);
    MyVector &operator=(const MyVector&);
    MyVector(MyVector&&) noexcept;
    MyVector &operator=(MyVector&&) noexcept;
    ~MyVector() noexcept;

    // additional constructor
    MyVector(std::initializer_list<T>);
    MyVector &operator=(std::initializer_list<T>);

    // add elements
    void push_back(const T&);
    void push_back(T&&);
    void insert(size_t index, const T &value);

    // del elements
    void pop_back();

    void clear();

    size_t getSize() const;
    size_t getCapacity() const;

    void resize(size_t n);
    void resize(size_t n, const T &s);

    // iterator
    T *begin() const;
    T *end() const;

    T &operator[](size_t n);
    const T &operator[](size_t n) const;

    void printElements() const;

    template<class... Args>
    void emplace_back(Args&&...);
};

#endif
