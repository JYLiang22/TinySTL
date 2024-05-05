#include"../src/Mypriority_queue.cpp"
#include<sstream>
#include<string>

int main(){

    Mypriority_queue<int, std::vector<int>> myPQ;

    int N; 
    std::cin >> N;
    getchar();

    std::string line;
    for(int i = 0; i < N; ++i){
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        int element;
        if(command == "push"){
            iss >> element;
            myPQ.push(element);
        }
        if(command == "pop"){
            try{
                myPQ.pop();
            }
            catch(const std::runtime_error &e){
                continue;
            }
        }
        if(command == "top"){
            try{
                std::cout << myPQ.top() << std::endl;
            }
            catch(const std::runtime_error &e){
                std::cout << "null" << std::endl;
            }
        }
        if(command == "size"){
            std::cout << myPQ.size() << std::endl;
        }
        if(command == "empty"){
            std::cout << (myPQ.empty() ? "true" : "false") << std::endl;
        }
    }

    return 0;
}