#pragma once

#ifndef _MYSET_H_
#define _MYSET_H_

#include"MyRedBlackTree.h" 

template<typename Key>
class MySet{
public:
    MySet();
    void insert(const Key &key);
    void erase(const Key &key);
    size_t size();
    bool empty();
    bool contains(const Key &key);

private:
    // template<typename _Key, typename Value> class MyRedBlackTree;
    MyRedBlackTree<Key, Key> rbTree;
};

#endif