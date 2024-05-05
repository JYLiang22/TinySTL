#include"../include/Mypriority_queue.h"
#include<stdexcept>

template<typename T, typename Container>
void Mypriority_queue<T, Container>::heapifyUp(){
    int idx = data.size() - 1;
    while(idx > 0){
        int parentIdx = (idx - 1) / 2;
        if(data[idx] > data[parentIdx]){
            std::swap(data[idx], data[parentIdx]);
            idx = parentIdx;
        }
        else{
            break;
        }
    }
}

template<typename T, typename Container>
void Mypriority_queue<T, Container>::heapifyDown(){
    int idx = 0;
    int size = data.size();
    while(true){
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int largest = idx;

        if(leftChild < size && data[leftChild] > data[largest]){
            largest = leftChild;
        }
        if(rightChild < size && data[rightChild] > data[largest]){
            largest = rightChild;
        }
        if(largest != idx){
            std::swap(data[idx], data[largest]);
            idx = largest;
        }
        else{
            break;
        }
    }
}

template<typename T, typename Container>
Mypriority_queue<T, Container>::Mypriority_queue() {}

template<typename T, typename Container>
Mypriority_queue<T, Container>::Mypriority_queue(const Container &c) : data(c){
    // 将底层容器转化为堆
    int size = data.size();
    for(int i = size / 2 - 1; i >= 0; --i){
        heapifyDown();
    }
}

template<typename T, typename Container>
void Mypriority_queue<T, Container>::push(const T &value){
    data.push_back(value);
    heapifyUp();
}

template<typename T, typename Container>
void Mypriority_queue<T, Container>::pop(){
    if(!empty()){
        std::swap(data[0], data[data.size() - 1]);
        data.pop_back();
        heapifyDown();
    }
    else{
        throw std::runtime_error("Priority queue is empty.");
    }
}

template<typename T, typename Container>
T& Mypriority_queue<T, Container>::top(){
    if(!empty()){
        return data[0];
    }
    else{
        throw std::runtime_error("Priority queue is empty.");
    }
}

template<typename T, typename Container>
bool Mypriority_queue<T, Container>::empty() const{
    return data.empty();
}

template<typename T, typename Container>
size_t Mypriority_queue<T, Container>::size() const{
    return data.size();
}
