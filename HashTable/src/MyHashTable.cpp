#include<iostream>
#include"../include/MyHashTable.h"

// ����MyHsahNode��غ���
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

// ����MyHashTable��غ���
// ������Ĺ�ϣֵ��������ӳ�䵽Ͱ������
template<typename Key, typename Value, typename MyHash>
size_t MyHashTable<Key, Value, MyHash>::hash(const Key &key) const{
    return hashFunction(key) % tableSize;
}

// ��Ԫ������������������Ӷ��������ʱ������Ͱ�����������·������м�
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::rehash(size_t newSize){
    std::vector<Bucket> newBuckets(newSize);   // �����µ�Ͱ����

    for(Bucket &bucket : buckets){   // ������Ͱ
        for(MyHashNode &myhashnode : bucket){   // ������Ͱ�е�ÿ����
            size_t newIdx = hashFunction(myhashnode.key) % newSize;   // Ϊ�������µ�����
            newBuckets[newIdx].push_back(myhashnode);   // ������ӵ���Ͱ��
        }
    }
    buckets = std::move(newBuckets);   // ʹ���ƶ��������Ͱ����
    tableSize = newSize;   // ���¹�ϣ���С
}

// ���캯����ʼ����ϣ��
template<typename Key, typename Value, typename MyHash>
MyHashTable<Key, Value, MyHash>::MyHashTable(size_t size, const MyHash &hashFunc) 
    : buckets(size), hashFunction(hashFunc), tableSize(size), numElements(0) {}

// ���������ϣ����
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::insert(const Key &key, const Value &value){
    if((numElements + 1) > maxLoadFactor * tableSize){   // ����Ƿ���Ҫ�ع�ϣ
        if(tableSize == 0){   // ����clear���ٴβ���Ԫ�� tableSize = 0 �����
            tableSize = 1;
        }
        rehash(tableSize * 2);
    }
    size_t idx = hash(key);   // �����������
    std::list<MyHashNode> &bucket = buckets[idx];   // ��ȡ��Ӧ��Ͱ
    // ���������Ͱ�У���ӽ�ȥ
    if(std::find(bucket.begin(), bucket.end(), key) == bucket.end()){
        bucket.emplace_back(key, value);
        ++numElements;
    }
}

template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::insertKey(const Key &key){
    insert(key, Value{});
}

// �ӹ�ϣ�����Ƴ���
template<typename Key, typename Value, typename MyHash>
void MyHashTable<Key, Value, MyHash>::erase(const Key &key){
    size_t idx = hash(key);   // �����������
    std::list<MyHashNode> &bucket = buckets[idx];
    typename std::list<MyHashNode>::iterator it = std::find(bucket.begin(), bucket.end(), key);
    if(it != bucket.end()){
        bucket.erase(it);   // �Ƴ���
        --numElements;
    }
}

// ���Ҽ��Ƿ�����ڹ�ϣ����
template<typename Key, typename Value, typename MyHash>
Value* MyHashTable<Key, Value, MyHash>::find(const Key &key){
    size_t idx = hash(key);   // �����������
    std::list<MyHashNode> &bucket = buckets[idx];   // ��ȡ��Ӧ��Ͱ
    typename std::list<MyHashNode>::iterator it = std::find(bucket.begin(), bucket.end(), key);
    if(it != bucket.end()){
        return &it->value;
    }
    return nullptr;
}

// ��ȡ��ϣ����Ԫ�ص�����
template<typename Key, typename Value, typename MyHash>
size_t MyHashTable<Key, Value, MyHash>::size() const{
    return numElements;
}

// ��ӡ��ϣ���е�����Ԫ��
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