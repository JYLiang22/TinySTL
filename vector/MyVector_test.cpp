#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<stdexcept>
#include "./src/MyVector.cpp"
#include "./include/MyVector.h"

int main(int argc, char *argv[]){

    MyVector<int> myVec;

    int N;
    std::cin >> N;
    // 读走回车
    getchar();

    std::string line;
    for(int i = 0; i < N; ++i){
        // 读取整行
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if(command == "push"){
            int value;
            iss >> value;
            myVec.push_back(value);
        }
        else if(command == "print"){
            if(myVec.getSize() == 0){
                std::cout << "Vector is empty" << std::endl;
                continue;
            }
            myVec.printElements();
        }
        else if(command == "size"){
            std::cout << "the size of vec is " << myVec.getSize() << std::endl;
        }
        else if(command == "get"){
            int index;
            iss >> index;
            std::cout << "the index num is " << myVec[index] << std::endl;
        }
        else if(command == "insert"){
            int index, value;
            iss >> index >> value;
            myVec.insert(index, value);
        }
        else if(command == "pop"){
            myVec.pop_back();
        }
        else if(command == "iterator"){
            if(myVec.getSize() == 0){
                std::cout << "the vec is empty" << std::endl;
                continue;
            }
            for(auto it = myVec.begin(); it != myVec.end(); ++it){
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        else if(command == "foreach"){
            if(myVec.getSize() == 0){
                std::cout << "the vec is empty" << std::endl;
                continue;
            }
            for(const auto &element : myVec){
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        else if(command == "clear"){
            myVec.clear();
        }
    }

    return 0;
}