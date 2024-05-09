#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include"../src/Myunordered_set.cpp"

int main(){

    MyUnorder_set<int> mySet;

    int N;
    std::cin >> N;
    getchar();

    std::string line;
    for (int i = 0; i < N; i++){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int element;

        if (command == "insert"){
            iss >> element;
            mySet.insert(element);
        }

        if (command == "erase"){
            iss >> element;
            mySet.erase(element);
        }

        if (command == "find"){
            iss >> element;
            std::cout << (mySet.find(element) ? "true" : "false") << std::endl;
        }

        if (command == "size"){
            std::cout << mySet.size() << std::endl;
        }

        if (command == "empty"){
            std::cout << (mySet.empty() ? "true" : "false") << std::endl;
        }
    }

    return 0;
}