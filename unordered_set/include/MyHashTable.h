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

            // 从Key构造节点，Value使用默认构造
            explicit MyHashNode(const Key &key);

            // 从Key和Value构造节点
            MyHashNode(const Key &key, const Value &value);

            // 比较运算符重载，只按照key进行比较
            bool operator==(const MyHashNode &other) const;
            bool operator!=(const MyHashNode &other) const;
            bool operator<(const MyHashNode &other) const;
            bool operator>(const MyHashNode &other) const;
            bool operator==(const Key key_) const;
            void print() const;
    };

private:
    using Bucket = std::list<MyHashNode>;   // 定义桶的类型为存储键的链表
    std::vector<Bucket> buckets;   // 存储所有桶的动态数组
    MyHash hashFunction;   // 哈希函数对象
    size_t tableSize;   // 哈希表的大小，即桶的数量
    size_t numElements;   // 哈希表中元素的数量

    float maxLoadFactor = 0.75;   // 默认的最大负载因子

    // 计算键的哈希值，并将其映射到桶的索引
    size_t hash(const Key &key) const;

    // 当元素数量超过最大负载因子定义的容量时，增加桶的数量并重新分配所有键
    void rehash(size_t newSize);

public:
    // 构造函数初始化哈希表
    MyHashTable(size_t size = 10, const MyHash &hashFunc = MyHash());

    // 插入键到哈希表中
    void insert(const Key &key, const Value &value);
    void insertKey(const Key &key);

    // 从哈希表中移除键
    void erase(const Key &key);

    // 查找键是否存在于哈希表中
    Value *find(const Key &key);

    // 获取哈希表中元素的数量
    size_t size() const;

    // 打印哈希表中所有元素
    void print() const;

    // 清空哈希表
    void clear();
};

#endif