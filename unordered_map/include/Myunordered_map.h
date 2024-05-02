#pragma once

#ifndef _MYUNORDERED_MAP_H_
#define _MYUNORDERED_MAP_H_

#include<iostream>
#include<cstddef>
#include"MyHashTable.h"

template<typename Key, typename Value>
class MyUnordered_map{
private:
    MyHashTable<Key, Value> hashtable;

public:
    MyUnordered_map();
    ~MyUnordered_map();

    bool empty() const noexcept;
    size_t size() const noexcept;
    void clear() noexcept;
    void insert(const Key &key, const Value &value);
    void erase(const Key &key);
    bool find(const Key &key);
    Value &operator[](const Key &key);
};

#endif