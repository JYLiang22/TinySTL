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
    // �����µĽڵ�
    Node *newNode = new Node(value, nullptr, this->tail);

    if(this->tail){
        // ����ǿգ���β�ڵ��nextָ��ָ���½ڵ�
        this->tail->next = newNode;
    }
    else{
        // �������Ϊ�գ��½ڵ�ͬʱҲ��ͷ�ڵ�
        this->head = newNode;
    }
    // ����β�ڵ�ָ��������С
    this->tail = newNode;
    ++this->size;
}

template<typename T>
void MyList<T>::push_front(const T &value){
    // �����µĽڵ�
    Node *newNode = new Node(value, this->head, nullptr);

    if(head){
        // �������ǿգ���ͷ�ڵ��prevָ��ָ���½ڵ�
        this->head->prev = newNode;
    }
    else{
        // �������Ϊ�գ��½ڵ�ͬ��Ҳ��β�ڵ�
        this->tail = newNode;
    }
    // ����ͷ�ڵ�ָ��������С
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
        // ��ȡβ�ڵ�ǰһ���ڵ�
        Node *newTail = this->tail->prev;

        // ɾ��β�ڵ�
        delete this->tail;

        // ����β�ڵ�ָ��������С
        this->tail = newTail;
        if(this->tail){
            this->tail->next = nullptr;
        }
        else{
            // ����Ϊ�գ�ͷ�ڵ��ÿ�
            this->head = nullptr;
        }
        --this->size;
    }
}

template<typename T>
void MyList<T>::pop_front(){
    if(this->size > 0){
        // ��ȡͷ�ڵ����һ���ڵ�
        Node *newHead = this->head->next;

        // ɾ��ͷ�ڵ�
        delete this->head;

        // ����ͷ�ڵ�ָ��������С
        this->head = newHead;
        if(this->head){
            this->head->prev = nullptr;
        }
        else{
            // ����Ϊ�գ�β�ڵ��ÿ�
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
        // �Ȳ���ͷ�ڵ�Ҳ����β�ڵ�
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    else if(node == this->head && node == this->tail){
        // ����ͷ�ڵ�Ҳ��β�ڵ�
        this->head = nullptr;
        this->tail = nullptr;
    }
    else if(node == this->head){
        // ��ͷ�ڵ�
        this->head = node->next;
        this->head->prev =nullptr;
    }
    else{
        // ��β�ڵ�
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

