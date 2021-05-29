#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>

struct tasks_possible{
    std::string task="unknown";
    std::time_t time;
};
void check(std::vector<tasks_possible>& tasks, tasks_possible& T, std::time_t& begin){
    std::time_t end=std::time(nullptr);
    if (!tasks.empty() && tasks[tasks.size()-1].time==begin){
        T.task=tasks[tasks.size()-1].task;
        T.time=std::difftime(end,begin);
        tasks.pop_back();
        tasks.push_back(T);
        std::cout<<tasks[tasks.size()-1].task<<" end in "<<std::put_time(std::localtime(&end),"%H:%M:%S")<<std::endl;
    }
}
void start(std::vector<tasks_possible>& tasks,tasks_possible& T,std::time_t& begin, std::string task){
    T.task=task;
    T.time=std::time(nullptr);
    begin=T.time;
    tasks.push_back(T);
    std::cout<<tasks[tasks.size()-1].task<<" begin in "<<std::put_time(std::localtime(&begin),"%H:%M:%S")<<std::endl;
}

void current(std::vector<tasks_possible>& tasks, std::time_t& begin){
    if (!tasks.empty()) {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].time != begin) {
                std::cout << tasks[i].task << " " << std::put_time(std::gmtime(&tasks[i].time), "%H:%M:%S")
                          << std::endl;
            }
            else{
                std::cout << "current now "<<tasks[i].task << " " << std::put_time(std::localtime(&begin), "%H:%M:%S")
                          << std::endl;
            }
        }
    }
}


int main() {
    tasks_possible T;
    std::vector<tasks_possible> tasks;
    std::time_t begin=std::time(nullptr);
    std::string  command,task;
    for (;;){
        std::cout<<"Input command"<<std::endl;
        std::cin>>command;
        if (command=="begin"){
            std::cout<<"Input task"<<std::endl;
            std::cin>>task;

            check(tasks,T,begin);
            start(tasks,T,begin,task);
        }
        else if (command=="end"){
            check(tasks,T, begin);
        }
        else if (command=="status"){
            current(tasks,begin);
        }
        else if (command== "exit"){
            break;
        }
    }

    return 0;
}
