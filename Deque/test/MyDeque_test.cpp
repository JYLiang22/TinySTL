#include<iostream>
#include<fstream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string.h>
#include<chrono>
#include<cstring>
#include<unistd.h>
#include<cstdio>
#include "../src/MyDeque.cpp"

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

int main(){

    // Measure time
    auto start = std::chrono::steady_clock::now();

    MyDeque<int> myDeque;

    // int N;
    // std::cin >> N;
    // getchar();

    std::ifstream in("../file/test.txt");
    // std::ifstream in("./file/data.txt");
    if(!in){
        std::cerr << "can not open the file!" << std::endl;
        return -1;
    }

    std::string line;
    while(std::getline(in, line)){
    // for(int i = 0; i < N; i++){
        // std::getline(std::cin, line);
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

    // Measure time
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time taken: " << elapsed_seconds.count() << " seconds" << std::endl;

    // Get memory usage
    unsigned long long memoryUsage = getMemoryUsage();
    std::cout << "Memory usage: " << memoryUsage << " KB" << std::endl;

    return 0;
}