#include<iostream>
#include "../include/MyVector.h"

// 构造、析构、拷贝构造、拷贝赋值等相关函数
template<typename T>
MyVector<T>::MyVector() : elements(nullptr), capacity(0), size(0) {}

template<typename T>
MyVector<T>::~MyVector(){
    delete[] this->elements;
}

template<typename T>
MyVector<T>::MyVector(const MyVector &other) : capacity(other.capacity), size(other.size){
    this->elements = new T[other.capacity];
    std::copy(other.elements, other.elements + other.size, this->elements);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector &other){
    if(this != &other){
        delete[] this->elements;
        this->capacity = other.capacity;
        this->size = other.size;
        this->elements = new T[this->capacity];
        std::copy(other.elements, other.elements + other.size, this->elements);
    }
    return *this;
}

template<typename T>
void MyVector<T>::push_back(const T &value){
    if(this->size == this->capacity){
        this->reserve(this->capacity == 0 ? 1 : 2 * this->capacity);
    }
    this->elements[this->size++] = value;
}

template<typename T>
size_t MyVector<T>::getSize() const{
    return this->size;
}

template<typename T>
size_t MyVector<T>::getCapacity() const{
    return this->capacity;
}

template<typename T>
T& MyVector<T>::operator[](size_t index){
    if(index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    return this->elements[index];
}

template<typename T>
const T& MyVector<T>::operator[](size_t index) const{
    if(index >= this->size){
        throw std::out_of_range("Index out of range");
    }
    return this->elements[index];
}

template<typename T>
void MyVector<T>::insert(size_t index, const T &value){
    if(index > this->size){
        throw std::out_of_range("Index out of range"); 
    }
    if(this->size == this->capacity){
        this->reserve(this->capacity == 0 ? 1 : this->capacity * 2);
    }
    for(size_t i = this->size; i > index; --i){
        this->elements[i] = this->elements[i - 1];
    }
    this->elements[index] = value;
    this->size++;
}

template<typename T>
void MyVector<T>::pop_back(){
    if(this->size > 0){
        --this->size;
    }
}

template<typename T>
void MyVector<T>::clear(){
    this->size = 0;
}

template<typename T>
T* MyVector<T>::begin(){
    return this->elements;
}

template<typename T>
T* MyVector<T>::end(){
    return this->elements + this->size;
}

template<typename T>
const T* MyVector<T>::begin() const{
    return this->elements;
}

template<typename T>
const T* MyVector<T>::end() const{
    return this->elements + this->size;
}

template<typename T>
void MyVector<T>::printElements() const{
    for(size_t i = 0; i < this->size; ++i){
        std::cout << this->elements[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void MyVector<T>::reserve(size_t newCapacity){
    if(newCapacity > this->capacity){
        T *newElements = new T[newCapacity];
        std::copy(this->elements, this->elements + this->size, newElements);
        delete[] this->elements;
        this->elements = newElements;
        this->capacity = newCapacity;
    }
}