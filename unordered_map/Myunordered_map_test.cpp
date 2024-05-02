#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include"./src/Myunordered_map.cpp"

int main(){

    MyUnordered_map<int, int> map;

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

        if(command == "insert"){
            iss >> key >> value;
            map.insert(key, value);
        }

        if(command == "erase"){
            iss >> key;
            map.erase(key);
        }

        if(command == "find"){
            iss >> key;
            if(map.find(key)){
                std::cout << "true" << std::endl;
            } 
            else{
                std::cout << "false" << std::endl;
            }
        }

        // size ÃüÁî
        if(command == "size"){
            std::cout << map.size() << std::endl;
        }

        // empty ÃüÁî
        if(command == "empty"){
            if(map.empty()){
                std::cout << "true" << std::endl;
            } 
            else{
                std::cout << "false" << std::endl;
            }
        }

        // clear ÃüÁî
        if(command == "clear"){
            map.clear();
        }
    }

    return 0;
}