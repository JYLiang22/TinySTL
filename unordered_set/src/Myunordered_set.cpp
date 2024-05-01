#include<iostream>
#include"../include/Myunordered_set.h"
#include"MyHashTable.cpp"

template<typename Key>
MyUnorder_set<Key>::MyUnorder_set() : hashtable() {}

template<typename Key>
MyUnorder_set<Key>::~MyUnorder_set() {}

template<typename Key>
bool MyUnorder_set<Key>::empty() const noexcept{
    return hashtable.size() == 0;
}

template<typename Key>
size_t MyUnorder_set<Key>::size() const noexcept{
    return hashtable.size();
}

template<typename Key>
void MyUnorder_set<Key>::clear() noexcept{
    hashtable.clear();
}

template<typename Key>
void MyUnorder_set<Key>::insert(Key key){
    hashtable.insertKey(key);
}

template<typename Key>
void MyUnorder_set<Key>::erase(Key key){
    hashtable.erase(key);
}

template<typename Key>
bool MyUnorder_set<Key>::find(const Key &key){
    return hashtable.find(key) != nullptr;
}