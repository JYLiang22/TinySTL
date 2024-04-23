#pragma once

#ifndef _MYLIST_H
#define _MYLIST_H

template<typename T>
class MyList{
public:
    template<typename L>
    friend std::ostream &operator<<(std::ostream &os, const MyList<L> &pt);

private:
    // 定义节点结构
    struct Node{
        T data;   // 数据
        Node *next;   // 指向下一个节点的指针
        Node *prev;   // 指向前一个节点的指针

        // 构造函数
        Node(const T &value, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };

    Node *head;   // 头节点指针
    Node *tail;   // 尾节点指针
    size_t size;   // 链表中节点的数量

public:
    MyList();   // 构造函数
    ~MyList();   // 析构函数

    void push_back(const T &value);   // 在链表末尾添加元素
    void push_front(const T &value);   // 在链表开头添加新的元素
    size_t getSize() const;   // 获取链表中节点的数量
    T &operator[](size_t index);   // 访问链表中的元素
    const T &operator[](size_t index) const;   // const版本访问链表中的元素
    void pop_back();   // 删除链表末尾的元素
    void pop_front();   // 删除链表开头的元素
    Node *getNode(const T &value);   // 获取指定值的节点
    T* find(const T &value);   // 链表里是否有指定值
    void remove(const T &value);   // 删除指定值的节点
    bool empty();
    void clear();   // 清空链表
    Node *begin();   // 使用迭代器遍历链表的开始位置
    Node *end();   // 使用迭代器遍历链表的结束位置
    const Node *begin() const;   // 使用迭代器遍历链表的开始位置(const版本)
    const Node *end() const;   // 使用迭代器遍历链表的结束位置(const版本)
    void printElements() const;   // 打印链表中的元素
};

#endif