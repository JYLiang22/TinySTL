#include<iostream>
#include<sstream>
#include<string>
#include"../src/MyRedBlackTree.cpp"

int main(){

    MyRedBlackTree<int, int> rbTree;

    int N;
    std::cin >> N;
    getchar();

    std::string line;
    for(int i = 0; i < N; i++){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int key;
        int value;

        if (command == "insert")
        {
            iss >> key >> value;
            rbTree.insert(key, value);
        }

        if (command == "size")
        {
            std::cout << rbTree.getSize() << std::endl;
        }

        if (command == "at")
        {
            iss >> key;
            int *res = rbTree.at(key);
            if (res == nullptr)
            {
                std::cout << "not exist" << std::endl;
            }
            else
            {
                std::cout << *res << std::endl;
            }
        }

        if (command == "remove")
        {
            iss >> key;
            rbTree.remove(key);
        }

        if (command == "print")
        {
            if (rbTree.empty())
            {
                std::cout << "empty" << std::endl;
            }
            else
            {
                rbTree.print();
            }
        }
    }

    return 0;
}