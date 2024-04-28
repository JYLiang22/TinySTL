#ifndef _MYHASHTABLE_H_
#define _MYHASHTABLE_H_

#include<iostream>
#include<list>
#include<vector>

template<typename Key, typename Value, typename MyHash = std::hash<Key>>
class MyHashTable{

    class MyHashNode{
        public:
            Key key;
            Value value;

            // ��Key����ڵ㣬Valueʹ��Ĭ�Ϲ���
            explicit MyHashNode(const Key &key);

            // ��Key��Value����ڵ�
            MyHashNode(const Key &key, const Value &value);

            // �Ƚ���������أ�ֻ����key���бȽ�
            bool operator==(const MyHashNode &other) const;
            bool operator!=(const MyHashNode &other) const;
            bool operator<(const MyHashNode &other) const;
            bool operator>(const MyHashNode &other) const;
            bool operator==(const Key key_) const;
            void print() const;
    };

private:
    using Bucket = std::list<MyHashNode>;   // ����Ͱ������Ϊ�洢��������
    std::vector<Bucket> buckets;   // �洢����Ͱ�Ķ�̬����
    MyHash hashFunction;   // ��ϣ��������
    size_t tableSize;   // ��ϣ��Ĵ�С����Ͱ������
    size_t numElements;   // ��ϣ����Ԫ�ص�����

    float maxLoadFactor = 0.75;   // Ĭ�ϵ����������

    // ������Ĺ�ϣֵ��������ӳ�䵽Ͱ������
    size_t hash(const Key &key) const;

    // ��Ԫ������������������Ӷ��������ʱ������Ͱ�����������·������м�
    void rehash(size_t newSize);

public:
    // ���캯����ʼ����ϣ��
    MyHashTable(size_t size = 10, const MyHash &hashFunc = MyHash());

    // ���������ϣ����
    void insert(const Key &key, const Value &value);
    void insertKey(const Key &key);

    // �ӹ�ϣ�����Ƴ���
    void erase(const Key &key);

    // ���Ҽ��Ƿ�����ڹ�ϣ����
    Value *find(const Key &key);

    // ��ȡ��ϣ����Ԫ�ص�����
    size_t size() const;

    // ��ӡ��ϣ��������Ԫ��
    void print() const;

    // ��չ�ϣ��
    void clear();
};

#endif