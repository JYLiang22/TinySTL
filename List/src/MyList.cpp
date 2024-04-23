#include<iostream>
#include"../include/MyList.h"

template<typename T>
std::ostream &operator<<(std::ostream &os, const MyList<T> &pt){
    for(typename MyList<T>::Node *current = pt.head; current; current = current->next){
        os << " " << current->data;
    }
    os << std::endl;
    return os;
}

template<typename T>
MyList<T>::MyList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
MyList<T>::~MyList() {
    this->clear();
}

template<typename T>
void MyList<T>::push_back(const T &value){
    // 创建新的节点
    Node *newNode = new Node(value, nullptr, this->tail);

    if(this->tail){
        // 链表非空，将尾节点的next指针指向新节点
        this->tail->next = newNode;
    }
    else{
        // 如果链表为空，新节点同时也是头节点
        this->head = newNode;
    }
    // 更新尾节点指针和链表大小
    this->tail = newNode;
    ++this->size;
}

template<typename T>
void MyList<T>::push_front(const T &value){
    // 创建新的节点
    Node *newNode = new Node(value, this->head, nullptr);

    if(head){
        // 如果链表非空，将头节点的prev指针指向新节点
        this->head->prev = newNode;
    }
    else{
        // 如果链表为空，新节点同样也是尾节点
        this->tail = newNode;
    }
    // 更新头节点指针和链表大小
    this->head = newNode;
    ++this->size;
}

template<typename T>
size_t MyList<T>::getSize() const{
    return this->size;
}

template<typename T>
T& MyList<T>::operator[](size_t index){
    if(index > this->size){
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for(size_t i = 0; i < index; ++i){
        current = current->next;
    }
    return current->data;
}

template<typename T>
const T& MyList<T>::operator[](size_t index) const{
    if(index > this->size){
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    for(size_t i = 0; i < index; ++i){
        current = current->next;
    }
    return current->data;
}

template<typename T>
void MyList<T>::pop_back(){
    if(this->size > 0){
        // 获取尾节点前一个节点
        Node *newTail = this->tail->prev;

        // 删除尾节点
        delete this->tail;

        // 更新尾节点指针和链表大小
        this->tail = newTail;
        if(this->tail){
            this->tail->next = nullptr;
        }
        else{
            // 链表为空，头节点置空
            this->head = nullptr;
        }
        --this->size;
    }
}

template<typename T>
void MyList<T>::pop_front(){
    if(this->size > 0){
        // 获取头节点的下一个节点
        Node *newHead = this->head->next;

        // 删除头节点
        delete this->head;

        // 更新头节点指针和链表大小
        this->head = newHead;
        if(this->head){
            this->head->prev = nullptr;
        }
        else{
            // 链表为空，尾节点置空
            this->tail = nullptr;
        }
        --this->size;
    }
}

template<typename T>
typename MyList<T>::Node* MyList<T>::getNode(const T &value){
    Node *node = head;
    while(node && node->data != value){
        node = node->next;
    }
    return node;
}

template<typename T>
T* MyList<T>::find(const T &value){
    Node *node = this->getNode(value);
    if(node == nullptr){
        return nullptr;
    }
    return &node->value;
}

template<typename T>
void MyList<T>::remove(const T &value){
    Node *node = this->getNode(value);
    if(node == nullptr){
        return;
    }
    if(node != this->head && node != this->tail){
        // 既不是头节点也不是尾节点
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    else if(node == this->head && node == this->tail){
        // 既是头节点也是尾节点
        this->head = nullptr;
        this->tail = nullptr;
    }
    else if(node == this->head){
        // 是头节点
        this->head = node->next;
        this->head->prev =nullptr;
    }
    else{
        // 是尾节点
        this->tail = node->prev;
        this->tail->next = nullptr;
    }

    --this->size;
    delete node;
    node = nullptr;
}

template<typename T>
bool MyList<T>::empty(){
    return this->size == 0;
}

template<typename T>
void MyList<T>::clear(){
    while(head){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    this->tail = nullptr;
    this->size = 0;
}

template<typename T>
typename MyList<T>::Node* MyList<T>::begin(){
    return this->head;
}

template<typename T>
typename MyList<T>::Node* MyList<T>::end(){
    return nullptr;
}

template<typename T>
const typename MyList<T>::Node* MyList<T>::begin() const{
    return this->head;
}

template<typename T>
const typename MyList<T>::Node* MyList<T>::end() const{
    return nullptr;
}

template<typename T>
void MyList<T>::printElements() const{
    for(Node *current = head; current; current = current->next){
        std::cout << current->data << " ";
    }
    std::cout << std::endl;
}

