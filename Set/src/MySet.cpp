#include<iostream>
#include"../include/MySet.h"
#include"MyRedBlackTree.cpp"

template<typename Key>
MySet<Key>::MySet() : rbTree() {}

template<typename Key>
void MySet<Key>::insert(const Key &key){
    rbTree.insert(key, key);
}

template<typename Key>
void MySet<Key>::erase(const Key &key){
    rbTree.remove(key);
}

template<typename Key>
size_t MySet<Key>::size(){
    return rbTree.getSize();
}

template<typename Key>
bool MySet<Key>::empty(){
    return rbTree.empty();
}

template<typename Key>
bool MySet<Key>::contains(const Key &key){
    return rbTree.at(key) != nullptr;
}