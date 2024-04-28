#include<iostream>
#include"../include/MyHashTable.h"

// 定义MyHsahNode相关函数
template<typename Key, typename Value, typename MyHash>
MyHashTable<Key, Value, MyHash>::MyHashNode::MyHashNode(const Key &key) : key(key), value() {}

template<typename Key, typename Value, typename MyHash>
MyHashTable<Key, Value, MyHash>::MyHashNode::MyHashNode(const Key &key, const Value &value) : key(key), value(value) {}

template<typename Key, typename Value, typename MyHash>
bool MyHashTable<Key, Value, MyHash>::MyHashNode::operator==(const MyHashNode &other) const{
    return key == other.key;
}

template<typename Key, typename Value, typename MyHash>
bool MyHashTable<Key, Value, MyHash>::MyHashNode::operator!=(const MyHashNode &other) const{
    return key != other.key;
}

template<typename Key, typename Value, typename MyHash>
bool MyHashTable<Key, Value, MyHash>::MyHashNode::operator<(const MyHashNode &other) const{
    return key < other.key;
}

template<typename Key, typename Value, typename MyHash>
bool MyHashTable<Key, Value, MyHash>::MyHashNode::operator>(const MyHashNode &other) const{
    return key > other.key;
}

template<typename Key, typename Value, typename MyHash>
bool MyHashTable<Key, Value, MyHash>::MyHashNode::operator==(const Key key_) const{
    return key == key_;
}

template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::MyHashNode::print() const{
    std::cout << key << " " << value << " ";
}

// 定义MyHashTable相关函数
// 计算键的哈希值，并将其映射到桶的索引
template<typename Key, typename Value, typename MyHash>
size_t MyHashTable<Key, Value, MyHash>::hash(const Key &key) const{
    return hashFunction(key) % tableSize;
}

// 当元素数量超过最大负载因子定义的容量时，增加桶的数量并重新分配所有键
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::rehash(size_t newSize){
    std::vector<Bucket> newBuckets(newSize);   // 创建新的桶数组

    for(Bucket &bucket : buckets){   // 遍历旧桶
        for(MyHashNode &myhashnode : bucket){   // 遍历旧桶中的每个键
            size_t newIdx = hashFunction(myhashnode.key) % newSize;   // 为键计算新的索引
            newBuckets[newIdx].push_back(myhashnode);   // 将键添加到新桶中
        }
    }
    buckets = std::move(newBuckets);   // 使用移动语义更新桶数组
    tableSize = newSize;   // 更新哈希表大小
}

// 构造函数初始化哈希表
template<typename Key, typename Value, typename MyHash>
MyHashTable<Key, Value, MyHash>::MyHashTable(size_t size, const MyHash &hashFunc) 
    : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

// 插入键到哈希表中
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::insert(const Key &key, const Value &value){
    if((numElements + 1) > maxLoadFactor * tableSize){   // 检查是否需要重哈希
        if(tableSize == 0){   // 处理clear后再次插入元素 tableSize = 0 的情况
            tableSize = 1;
        }
        rehash(tableSize * 2);
    }
    size_t idx = hash(key);   // 计算键的索引
    std::list<MyHashNode> &bucket = buckets[idx];   // 获取对应的桶
    // 如果键不在桶中，添加进去
    if(std::find(bucket.begin(), bucket.end(), key) == bucket.end()){
        bucket.emplace_back(key, value);
        ++numElements;
    }
}

template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::insertKey(const Key &key){
    insert(key, Value{});
}

// 从哈希表中移除键
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::erase(const Key &key){
    size_t idx = hash(key);   // 计算键的索引
    std::list<MyHashNode> &bucket = buckets[idx];
    typename std::list<MyHashNode>::iterator it = std::find(bucket.begin(), bucket.end(), key);
    if(it != bucket.end()){
        bucket.erase(it);   // 移除键
        --numElements;
    }
}

// 查找键是否存在于哈希表中
template<typename Key, typename Value, typename MyHash>
Value* MyHashTable<Key, Value, MyHash>::find(const Key &key){
    size_t idx = hash(key);   // 计算键的索引
    std::list<MyHashNode> &bucket = buckets[idx];   // 获取对应的桶
    typename std::list<MyHashNode>::iterator it = std::find(bucket.begin(), bucket.end(), key);
    if(it != bucket.end()){
        return &it->value;
    }
    return nullptr;
}

// 获取哈希表中元素的数量
template<typename Key, typename Value, typename MyHash>
size_t MyHashTable<Key, Value, MyHash>::size() const{
    return numElements;
}

// 打印哈希表中的所有元素
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::print() const{
    for(auto bucket : buckets){
        for(auto element : bucket){
            element.print();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::clear(){
    this->buckets.clear();
    this->numElements = 0;
    this->tableSize = 0;
}