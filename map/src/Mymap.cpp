#include<iostream>
#include"../include/Mymap.h"
#include"MyRedBlackTree.cpp"

template<typename Key, typename Value>
Mymap<Key, Value>::Mymap() : rbTree() {}

template<typename Key, typename Value>
Mymap<Key, Value>::~Mymap() {}

template<typename Key, typename Value>
void Mymap<Key, Value>::insert(const Key &key, const Value &value){
    rbTree.insert(key, value);
}

template<typename Key, typename Value>
void Mymap<Key, Value>::erase(const Key &key){
    rbTree.remove(key);
}

template<typename Key, typename Value>
size_t Mymap<Key, Value>::size(){
    return rbTree.getSize();
}

template<typename Key, typename Value>
bool Mymap<Key, Value>::empty(){
    return rbTree.empty();
}

template<typename Key, typename Value>
bool Mymap<Key, Value>::contains(const Key &key){
    return rbTree.at(key) != nullptr;
}

template<typename Key, typename Value>
Value& Mymap<Key, Value>::at(const Key &key){
    Value *foundVal = rbTree.at(key);
    if(foundVal){
        return *foundVal;
    }
    else{
        throw std::out_of_range("key not found");
    }
}

template<typename Key, typename Value>
Value& Mymap<Key, Value>::operator[](const Key &key){
    Value *foundVal = rbTree.at(key);
    if(foundVal){
        return *foundVal;
    }
    else{
        Value defaultValue;
        rbTree.insert(key, defaultValue);
        return *rbTree.at(key);
    }
}

template<typename Key, typename Value>
void Mymap<Key, Value>::clear(){
    rbTree.clear();
}