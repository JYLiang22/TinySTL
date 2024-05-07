#include<iostream>
#include<algorithm>
#include<memory>
#include<utility>
#include<initializer_list>
#include "../include/MyVector_opti.h"
using namespace std;

template<typename T>
std::allocator<T> MyVector<T>::alloc;

// utility functions
// used by members that add elements to the StrVec
template<typename T>
void MyVector<T>::chk_n_alloc(){
    if(getSize() == getCapacity()){
        reallocate();
    }
}

// to judge whether the capacity if satisfied the need
template<typename T>
void MyVector<T>::reserve(size_t n){
    if(n > getCapacity()){
        reallocate(n);
    }
}

// destroy the elements and free the space
template<typename T>
void MyVector<T>::free(){
    // may not pass deallocate a 0 pointer; if elements is 0, there's no work to do
    if(elements){
        // destroy the old elements in reverse order
        for(T *p = first_free; p != elements; ){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

// get more space and copy the existing elements
template<typename T>
void MyVector<T>::reallocate(){
    size_t newcapacity = getSize() ? 2 * getSize() : 1;
    
    // // allocate new memory
    // T *newdata = alloc.allocate(newcapacity);

    // // move the data from the old memory to the new
    // T *dest = newdata;   // points to the next free position in the new array
    // T *elem = elements;   // points to the next element in the old array
    // for(size_t i = 0; i != getSize(); ++i){
    //     alloc.construct(dest++, std::move(*elem++));
    // }

    // free();  // free the old space once we've moved the elements

    // // update our data structure to point to the new elements
    // elements = newdata;
    // first_free = dest;
    // cap = elements + newcapacity;

    // use move iterator
    T *first = alloc.allocate(newcapacity);
    // move elements
    T *last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free();

    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

// get more space and copy the existing elements
template<typename T>
void MyVector<T>::reallocate(size_t newcapacity){
    // alloc new memory
    T *newdata = alloc.allocate(newcapacity);

    // // move the data from the old memory to the new
    // T *dest = newdata;   // points to the next free position in the new array
    // T *elem = elements;   // points to the next element in the old array
    // for(size_t i = 0; i != getSize(); ++i){
    //     alloc.construct(dest++, std::move(*elem++));
    // }

    // use move iterator
    T *dest = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), newdata);

    free();  // free the old space once we've moved the elements

    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template<typename T>
MyVector<T>::MyVector() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

template<typename T>
MyVector<T>::MyVector(const MyVector &v){
    std::pair<T*, T*> newdata = alloc_n_copy(v.begin(), v.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector &rhs){
    // call alloc_n_copy to allocate exactly as many elements as in rhs
    std::pair<T*, T*> data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector &&s) noexcept   // move won't throw any exceptions
    : elements(s.elements), first_free(s.first_free), cap(s.cap){   
    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector &&rhs) noexcept{
    // direct test for self-assignment
    if(this != &rhs){
        free();   // free existing elements 
        // take over resources from rhs
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template<typename T>
MyVector<T>::~MyVector() noexcept{
    free();
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> il){
    // call alloc_n_copy to allocate exactly as many elements as in il
    std::pair<T*, T*> newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(std::initializer_list<T> il){
    // alloc_n_copy allocates space and copies elements from the given range
    std::pair<T*, T*> data = alloc_n_copy(il.begin(), il.end());
    free();   // destroy the elements in this object and free the space
    // update data members to point to the new space
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
void MyVector<T>::push_back(const T &s){
    chk_n_alloc();   // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}

template<typename T>
void MyVector<T>::push_back(T &&s){
    chk_n_alloc();   // reallocates the StrVec if necessary
	alloc.construct(first_free++, std::move(s));
}

template<typename T>
void MyVector<T>::insert(size_t index, const T &value){
    if(index < 0 || index > getSize()){
        throw std::out_of_range("inde out of range");
    }
    chk_n_alloc();   // ensure that there is room for another element
    alloc.construct(first_free++, elements[getSize() - 1]);
    for(size_t i = getSize() - 2; i > index; --i){
        elements[i] = elements[i - 1];
    }
    elements[index] = value;
}

template<typename T>
void MyVector<T>::pop_back(){
    if(getSize()){
        alloc.destroy(--first_free);
    }
}

template<typename T>
void MyVector<T>::clear(){
    elements = first_free = cap = nullptr;
}

template<typename T>
size_t MyVector<T>::getSize() const{
    return first_free - elements;
}

template<typename T>
size_t MyVector<T>::getCapacity() const{
    return cap - elements;
}

template<typename T>
void MyVector<T>::resize(size_t n){
    if(n > getSize()){
        while(getSize() < n){
            // while T is int
            push_back(INT32_MIN);
        }
    }
    else if(n < getSize()){
        while(getSize() > n){
            alloc.destroy(--first_free);
        }
    }
}

template<typename T>
T* MyVector<T>::begin() const{
    return elements;
}

template<typename T>
T* MyVector<T>::end() const{
    return first_free;;
}

template<typename T>
T& MyVector<T>::operator[](size_t n){
    return elements[n];
}

template<typename T>
const T& MyVector<T>::operator[](size_t n) const{
    return elements[n];
}

template<typename T>
void MyVector<T>::printElements() const{
    for(T *it = elements; it != first_free; ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}   

template<typename T>
template<class... Args>
void MyVector<T>::emplace_back(Args&&... args){
    chk_n_alloc();   // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
