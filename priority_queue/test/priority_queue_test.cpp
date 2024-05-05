#include"../src/priority_queue.cpp"
#include<iostream>

int main(){

    Priority_queue<int> pq1;

    pq1.push(3);
    pq1.push(1);
    pq1.push(4);
    pq1.push(1);

    std::cout << "Top element of pq1: " << pq1.top() << std::endl;

    pq1.pop();
    std::cout << "Priority queue pq1 size after pop: " << pq1.size() << std::endl;

    // 使用 std::vector 作为底层容器的示例
    std::vector<int> vec = {9, 5, 7, 2, 6};
    Priority_queue<int, std::vector<int>> pq2(vec);

    std::cout << "Top element of pq2: " << pq2.top() << std::endl;

    pq2.pop();
    std::cout << "Priority queue pq2 size after pop: " << pq2.size() << std::endl;

    return 0;
}