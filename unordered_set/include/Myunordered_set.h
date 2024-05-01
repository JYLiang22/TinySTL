#pragma once

#ifndef _MYUNORDER_SET_H_
#define _MYUNORDER_SET_H_

#include"MyHashTable.h"

template<typename Key>
class MyUnorder_set{
public:
    MyUnorder_set();
    ~MyUnorder_set();

    bool empty() const noexcept;
    size_t size() const noexcept;
    void clear() noexcept;
    void insert(Key key);
    void erase(Key key);
    bool find(const Key &key);

private:
    MyHashTable<Key, Key> hashtable;
};

#endif