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

    // ����Ԫ��
    void insert(const Key &key);

    // ɾ����Ϊkey��Ԫ��
    void erase(const Key &key);

    // ���������е�Ԫ��
    size_t size() const;

    // �ж������Ƿ�Ϊ��
    bool empty() const;

    // ������multiset�е��ڸ���ֵ��Ԫ�ص�����
    size_t count(const Key &key);

    void clear();
};

#endif