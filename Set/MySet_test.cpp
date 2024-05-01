#include<iostream>
#include<sstream>
#include<string>
#include"./src/MySet.cpp"

int main(){

    MySet<int> mySet;

    int N;
    std::cin >> N;
    getchar();

    std::string line;
    for(int i = 0; i < N; i++){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int element;

        if(command == "insert"){
            iss >> element;
            mySet.insert(element);
        }

        if (command == "earse"){
            iss >> element;
            mySet.erase(element);
        }

        if (command == "contains"){
            iss >> element;
            std::cout << (mySet.contains(element) ? "true" : "false") << std::endl;
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