#include<iostream>
#include"../include/Mystack.h"
#include"MyDeque.cpp"

// template<typename T, typename Container>
// MyStack<T, Container>::MyStack(){}

// template<typename T, typename Container>
// MyStack<T, Container>::~MyStack(){
//     data.~MyDeque();
// }

template<typename T, typename Container>
void MyStack<T, Container>::push(const T &value){
    data.push_back(value);
}

template<typename T, typename Container>
void MyStack<T, Container>::pop(){
    if(data.getSize() == 0){
        throw std::runtime_error("Stack is empty.");
    }
    else{
        data.pop_back();
    }
}

template<typename T, typename Container>
T& MyStack<T, Container>::top(){
    if(!empty()){
        return data.back();
    }
    else{
        throw std::runtime_error("Stack is empty.");
    }
}

template<typename T, typename Container>
bool MyStack<T, Container>::empty() const{
    return data.getSize() == 0;
}

template<typename T, typename Container>
size_t MyStack<T, Container>::size() const{
    return data.getSize();
}

template<typename T, typename Container>
void MyStack<T, Container>::clear(){
    data.clear();
}
