#include<iostream>
#include<stdexcept>
#include "../include/MyDeque.h"

template<typename T>
MyDeque<T>::MyDeque() : elements(nullptr), capacity(0), frontIdx(0), backIdx(0), size(0) {}

template<typename T>
MyDeque<T>::~MyDeque(){
    clear();
    delete []elements;
}

template<typename T>
void MyDeque<T>::push_front(const T& val){
    if(size == capacity)
        resize();
    frontIdx = (frontIdx - 1 + capacity) % capacity;
    elements[frontIdx] = val;
    ++size;
}

template<typename T>
void MyDeque<T>::push_back(const T& val){
    if(size == capacity)
        resize();
    elements[backIdx] = val;
    backIdx = (backIdx + 1) % capacity;
    ++size;
}

template<typename T>
void MyDeque<T>::pop_front(){
    if(size == 0){
        throw std::out_of_range("MyDeque is empty");
    }
    frontIdx = (frontIdx + 1) % capacity;
    --size;
}

template<typename T>
void MyDeque<T>::pop_back(){
    if(size == 0){
        throw std::out_of_range("MyDeque is empty");
    }
    backIdx = (backIdx - 1 + capacity) % capacity;
    --size;
}

template<typename T>
T& MyDeque<T>::operator[](int idx){
    if(idx < 0 || idx >= size){
        throw std::out_of_range("Index out of range");
    }
    return elements[(frontIdx + idx) % capacity];
}

template<typename T>
size_t MyDeque<T>::getSize() const{
    return size;
}

template<typename T>
void MyDeque<T>::clear(){
    while(size > 0){
        pop_front();
    }
}

template<typename T>
void MyDeque<T>::printElements() const{
    size_t idx = frontIdx;
    for(size_t i = 0; i < size; ++i){
        std::cout << elements[idx] << " ";
        idx = (idx + 1) % capacity;
    }
    std::cout << std::endl;
}

template<typename T>
void MyDeque<T>::resize(){
    size_t newCapacity = (capacity == 0) ? 1 : 2 * capacity;
    T* newElements = new T[newCapacity];
    size_t idx = frontIdx;
    for(size_t i = 0; i < size; ++i){
        newElements[i] = elements[idx];
        idx = (idx + 1) % capacity;
    }
    delete []elements;
    elements = newElements;
    capacity = newCapacity;
    frontIdx = 0;
    backIdx = size;
}