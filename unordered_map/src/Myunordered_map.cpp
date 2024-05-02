#include<iostream>
#include<cstddef>
#include"MyHashTable.cpp"
#include"../include/Myunordered_map.h"

template<typename Key, typename Value>
MyUnordered_map<Key, Value>::MyUnordered_map() : hashtable() {}

template<typename Key, typename Value>
MyUnordered_map<Key, Value>::~MyUnordered_map() {}

template<typename Key, typename Value>
bool MyUnordered_map<Key, Value>::empty() const noexcept{
    return hashtable.size() == 0;
}

template<typename Key, typename Value>
size_t MyUnordered_map<Key, Value>::size() const noexcept{
    return hashtable.size();
}

template<typename Key, typename Value>
void MyUnordered_map<Key, Value>::clear() noexcept{
    hashtable.clear();
}

template<typename Key, typename Value>
void MyUnordered_map<Key, Value>::insert(const Key &key, const Value &value){
    hashtable.insert(key, value);
}

template<typename Key, typename Value>
void MyUnordered_map<Key, Value>::erase(const Key &key){
    hashtable.erase(key);
}

template<typename Key, typename Value>
bool MyUnordered_map<Key, Value>::find(const Key &key){
    return hashtable.find(key) != nullptr;
}

template<typename Key, typename Value>
Value& MyUnordered_map<Key, Value>::operator[](const Key &key){
    Value *res = hashtable.find(key);
    if(res){
        return *res;
    }
    hashtable.insertKey(key);
    res = hashtable.find(key);
    return *res;
}