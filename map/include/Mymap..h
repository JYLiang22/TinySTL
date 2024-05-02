#ifndef _MYMAP_H_
#define _MYMAP_H_

#include"MyRedBlackTree.h"

template<typename Key, typename Value>
class Mymap{
public:
    Mymap();
    ~Mymap();

    void insert(const Key &key, const Value &value);
    void erase(const Key &key);
    size_t size();
    bool empty();
    bool contains(const Key &key);
    Value &at(const Key &key);
    Value &operator[](const Key &key);
    void clear();

private:
    MyRedBlackTree<Key, Value> rbTree;
};

#endif