#pragma once

#ifndef _MYLIST_H
#define _MYLIST_H

template<typename T>
class MyList{
public:
    template<typename L>
    friend std::ostream &operator<<(std::ostream &os, const MyList<L> &pt);

private:
    // ����ڵ�ṹ
    struct Node{
        T data;   // ����
        Node *next;   // ָ����һ���ڵ��ָ��
        Node *prev;   // ָ��ǰһ���ڵ��ָ��

        // ���캯��
        Node(const T &value, Node *nextNode = nullptr, Node *prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };

    Node *head;   // ͷ�ڵ�ָ��
    Node *tail;   // β�ڵ�ָ��
    size_t size;   // �����нڵ������

public:
    MyList();   // ���캯��
    ~MyList();   // ��������

    void push_back(const T &value);   // ������ĩβ���Ԫ��
    void push_front(const T &value);   // ������ͷ����µ�Ԫ��
    size_t getSize() const;   // ��ȡ�����нڵ������
    T &operator[](size_t index);   // ���������е�Ԫ��
    const T &operator[](size_t index) const;   // const�汾���������е�Ԫ��
    void pop_back();   // ɾ������ĩβ��Ԫ��
    void pop_front();   // ɾ������ͷ��Ԫ��
    Node *getNode(const T &value);   // ��ȡָ��ֵ�Ľڵ�
    T* find(const T &value);   // �������Ƿ���ָ��ֵ
    void remove(const T &value);   // ɾ��ָ��ֵ�Ľڵ�
    bool empty();
    void clear();   // �������
    Node *begin();   // ʹ�õ�������������Ŀ�ʼλ��
    Node *end();   // ʹ�õ�������������Ľ���λ��
    const Node *begin() const;   // ʹ�õ�������������Ŀ�ʼλ��(const�汾)
    const Node *end() const;   // ʹ�õ�������������Ľ���λ��(const�汾)
    void printElements() const;   // ��ӡ�����е�Ԫ��
};

#endif