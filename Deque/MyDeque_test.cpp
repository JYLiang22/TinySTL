#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include "./src/MyDeque.cpp"

int main(){

    MyDeque<int> myDeque;

    int N;
    std::cin >> N;
    getchar();
    std::string line;
    for(int i = 0; i < N; i++){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        int value;

        if (command == "push_back") {
            iss >> value;
            myDeque.push_back(value);
        }

        if (command == "push_front") {
            iss >> value;
            myDeque.push_front(value);
        }

        if (command == "pop_back") {
            if (myDeque.getSize() == 0) {
                continue;
            }
            myDeque.pop_back();
        }

        if (command == "pop_front") {
            if (myDeque.getSize() == 0) {
                continue;
            }
            myDeque.pop_front();
        }

        if (command == "clear") {
            myDeque.clear();
        }

        if (command == "size") {
            std::cout << myDeque.getSize() << std::endl;
        }

        if (command == "get") {
            iss >> value;
            std::cout << myDeque[value] << std::endl;
        }

        if (command == "print") {
            if (myDeque.getSize() == 0) {
                std::cout << "empty" << std::endl;
            } else {
                myDeque.printElements();
            }
        }
    }

    return 0;
}