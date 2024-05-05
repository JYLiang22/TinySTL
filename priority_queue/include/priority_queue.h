#pragma once

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include<iostream>
#include<vector>

template<typename T, typename Container = std::vector<T>>
class Priority_queue{
private:
    Container data;

public:
    Priority_queue();
    Priority_queue(const Container &c);

    void push(const T &value);
    void pop();
    T& top();
    bool empty() const;
    size_t size() const;    
};

#endif