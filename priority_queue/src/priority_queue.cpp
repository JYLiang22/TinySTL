#include"../include/priority_queue.h"
#include<algorithm>

template<typename T, typename Container>
Priority_queue<T, Container>::Priority_queue(){

}

template<typename T, typename Container>
Priority_queue<T, Container>::Priority_queue(const Container &c) : data(c){
    std::make_heap(data.begin(), data.end());
}

template<typename T, typename Container>
void Priority_queue<T, Container>::push(const T &value){
    data.push_back(value);
    std::push_heap(data.begin(), data.end());
}

template<typename T, typename Container>
void Priority_queue<T, Container>::pop(){
    if(!empty()){
        std::pop_heap(data.begin(), data.end());
        data.pop_back();
    }
    else{
        throw std::runtime_error("Priority queue is empty.");
    }
}

template<typename T, typename Container>
T& Priority_queue<T, Container>::top(){
    if(!empty()){
        return data.front();
    } 
    else{
        throw std::runtime_error("Priority queue is empty.");
    }
}

template<typename T, typename Container>
bool Priority_queue<T, Container>::empty() const{
    return data.empty();
}

template<typename T, typename Container>
size_t Priority_queue<T, Container>::size() const{
    return data.size();
}
