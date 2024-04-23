#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>
#include"./src/MyList.cpp"

int main(int argc, char *argv[]){

    MyList<int> myList;

    int N;
    std::cin >> N;
    getchar();   // ¶Á×ß»Ø³µ
    std::string line;
    for(int i = 0; i < N; ++i){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        if (command == "push_back") {
            iss >> value;
            myList.push_back(value);
        }
        if (command == "push_front") {
            iss >> value;
            myList.push_front(value);
        }
        if (command == "pop_back") {
            myList.pop_back();
        }
        if (command == "pop_front") {
            myList.pop_front();
        }
        if (command == "remove") {
            iss >> value;
            myList.remove(value);
        }
        if (command == "clear") {
            myList.clear();
        }
        if (command == "size") {
            std::cout << myList.getSize() << std::endl;
        }
        if (command == "get") {
            iss >> value;
            std::cout << myList[value] << std::endl;
        }
        if (command == "print") {
            if (myList.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myList.printElements();
            }
        }
    }

    return 0;
}