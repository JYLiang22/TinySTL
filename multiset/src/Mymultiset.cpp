#include<iostream>
#include"../include/Mymultiset.h"
#include"MyRedBlackTree.cpp"

template<typename Key>
MyMultiSet<Key>::MyMultiSet() : sz(0) {}

template<typename Key>
MyMultiSet<Key>::~MyMultiSet() {}

template<typename Key>
void MyMultiSet<Key>::insert(const Key &key){
    size_t *count = rbTree.at(key);
    if(count != nullptr){
        ++(*count);
        ++sz;
        return;
    }
    rbTree.insert(key, 1);
    ++sz;
}

template<typename Key>
void MyMultiSet<Key>::erase(const Key &key){
    size_t *count = rbTree.at(key);
    if(count == nullptr){
        return;
    }
    --(*count);
    --sz;
    if((*count) == 0){
        rbTree.remove(key);
    }
}

template<typename Key>
size_t MyMultiSet<Key>::size() const{
    return sz;
}

template<typename Key>
bool MyMultiSet<Key>::empty() const{
    return sz == 0;
}

template<typename Key>
size_t MyMultiSet<Key>::count(const Key &key){
    size_t *num = rbTree.at(key);
    if(num != nullptr){
        return *num;
    }
    return 0;
}

template<typename Key>
void MyMultiSet<Key>::clear(){
    sz = 0;
    rbTree.clear();
}