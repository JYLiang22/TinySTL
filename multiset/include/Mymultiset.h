#ifndef _MYMULTISET_H_
#define _MYMULTISET_H_

#include"MyRedBlackTree.h"

template<typename Key>
class MyMultiSet{
    MyRedBlackTree<Key, size_t> rbTree;
    size_t sz;

public:
    MyMultiSet();
    ~MyMultiSet();

    // 插入元素
    void insert(const Key &key);

    // 删除键为key的元素
    void erase(const Key &key);

    // 返回容器中的元素
    size_t size() const;

    // 判断容器是否为空
    bool empty() const;

    // 返回在multiset中等于给定值的元素的数量
    size_t count(const Key &key);

    void clear();
};

#endif