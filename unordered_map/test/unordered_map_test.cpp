#include<iostream>
#include<fstream>
#include<random>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string.h>
#include<chrono>
#include<cstring>
#include<unistd.h>
#include<cstdio>
#include<unordered_map>

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

    std::unordered_map<int, int> map;

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
    //     std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;
        
        int key;
        int value;

        if(command == "insert"){
            iss >> key >> value;
            map.insert({key, value});
        }

        if(command == "erase"){
            iss >> key;
            map.erase(key);
        }

        if(command == "find"){
            iss >> key;
            if(map.find(key) != map.end()){
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

    // Measure time
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "Time taken: " << elapsed_seconds.count() << " seconds" << std::endl;

    // Get memory usage
    unsigned long long memoryUsage = getMemoryUsage();
    std::cout << "Memory usage: " << memoryUsage << " KB" << std::endl;

    return 0;
}