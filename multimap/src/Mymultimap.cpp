#include<iostream>
#include"MyRedBlackTree.cpp"
#include"../include/Mymultimap.h"

template<typename Key, typename Value>
MyMultiMap<Key, Value>::MyMultiMap() : rbTree(), size(0) {}

template<typename Key, typename Value>
MyMultiMap<Key, Value>::~MyMultiMap() {}

template<typename Key, typename Value>
void MyMultiMap<Key, Value>::insert(const Key &key, const Value &value){
    ValueType *val = rbTree.at(key);
    if(val){
        val->push_back(value);
    }
    else{
        ValueType values;
        values.push_back(value);
        rbTree.insert(key, values);
    }
    ++size;
}

template<typename Key, typename Value>
void MyMultiMap<Key, Value>::remove(const Key &key){
    ValueType *res = rbTree.at(key);
    if(res){
        size -= res->size();
        rbTree.remove(key);
    }
}

template<typename Key, typename Value>
void MyMultiMap<Key, Value>::remove(const Key &key, const Value &value){
    ValueType *res = rbTree.at(key);
    if(res){
        res->remove(value);
        --size;
        if(res->empty()){
            rbTree.remove(key);
        }
    }
}

template<typename Key, typename Value>
void MyMultiMap<Key, Value>::clear(){
    size = 0;
    rbTree.clear();
}

template<typename Key, typename Value>
typename MyMultiMap<Key, Value>::ValueType* MyMultiMap<Key, Value>::at(const Key &key){
    return rbTree.at(key);
}

template<typename Key, typename Value>
int MyMultiMap<Key, Value>::getSize(){
    return size;
}

template<typename Key, typename Value>
bool MyMultiMap<Key, Value>::empty(){
    return size == 0;
}

