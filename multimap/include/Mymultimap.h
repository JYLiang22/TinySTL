#pragma once

#ifndef _MYMULTIMAP_H_
#define _MYMULTIMAP_H_

#include<iostream>
#include<list>
#include"MyRedBlackTree.h"

template<typename Key, typename Value>
class MyMultiMap{
public:
    using ValueType = std::list<Value>;

    MyMultiMap();
    ~MyMultiMap();

    void insert(const Key &key, const Value &value);
    void remove(const Key &key);
    void remove(const Key &key, const Value &value);
    void clear();
    ValueType *at(const Key &key);
    int getSize();
    bool empty();

private:
    MyRedBlackTree<Key, ValueType> rbTree;
    size_t size;
};

#endif