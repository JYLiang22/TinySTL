#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>
#include<string>
#include<stdexcept>
#include<chrono>
#include<cstring>
#include<unistd.h>
#include<cstdio>
#include "./src/MyVector.cpp"

// Function to read memory usage from /proc/self/status
unsigned long long getMemoryUsage() {
    FILE* file = fopen("/proc/self/status", "r");
    char line[128];

    while (fgets(line, 128, file) != nullptr) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            fclose(file);
            // Extract memory usage value
            unsigned long long memory;
            sscanf(line, "VmRSS: %llu kB", &memory);
            return memory;
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]){

    // Measure time
    auto start = std::chrono::steady_clock::now();

    MyVector<int> myVec;

    // int N;
    // std::cin >> N;
    // // 读走回车
    // getchar();

    // std::ifstream in("./file/test.txt");
    std::ifstream in("./file/data.txt");
    if(!in){
        std::cerr << "can not open the file!" << std::endl;
        return -1;
    }



    std::string line;
    // for(int i = 0; i < N; ++i){
    while(std::getline(in, line)){
        // 读取整行
        // std::getline(in, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if(command == "push"){
            int value;
            iss >> value;
            myVec.push_back(value);
            // std::cout << "done" << std::endl;
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

    // Measure time
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time taken: " << elapsed_seconds.count() << " seconds" << std::endl;

    // Get memory usage
    unsigned long long memoryUsage = getMemoryUsage();
    std::cout << "Memory usage: " << memoryUsage << " KB" << std::endl;

    return 0;
}

