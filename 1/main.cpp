#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>

struct tasks_possible{
    std::vector<std::string> task;
    std::vector<std::time_t> time;
};
void check(tasks_possible& tasks, std::time_t& begin){
    std::time_t end=std::time(nullptr);
    if (!tasks.time.empty() && tasks.time[tasks.time.size()-1]==begin){
        tasks.time.pop_back();
        tasks.time.push_back(std::difftime(end,begin));
        std::cout<<tasks.task[tasks.time.size()-1]<<" end in "<<std::put_time(std::localtime(&end),"%H:%M:%S")<<std::endl;
    }
}
void start(tasks_possible& tasks,std::time_t& begin){
    begin=std::time(nullptr);
    tasks.time.push_back(begin);
    std::cout<<tasks.task[tasks.task.size()-1]<<" begin in "<<std::put_time(std::localtime(&begin),"%H:%M:%S")<<std::endl;
}

void current(tasks_possible& tasks, std::time_t& begin){
    if (!tasks.time.empty()) {
        for (int i = 0; i < tasks.task.size(); i++) {
            if (tasks.time[i] != begin) {
                std::cout << tasks.task[i] << " " << std::put_time(std::localtime(&tasks.time[i]), "%H:%M:%S")
                          << std::endl;
            }
            else{
                std::cout << "current now "<<tasks.task[i] << " " << std::put_time(std::localtime(&tasks.time[i]), "%H:%M:%S")
                          << std::endl;
            }
        }
    }
}


int main() {
    tasks_possible tasks;
    std::time_t begin=std::time(nullptr);;
    std::string  command,task;
    for (;;){
        std::cout<<"Input command"<<std::endl;
        std::cin>>command;
        if (command=="begin"){
            std::cout<<"Input task"<<std::endl;
            std::cin>>task;
            tasks.task.push_back(task);
            check(tasks,begin);
            start(tasks,begin);
        }
        else if (command=="end"){
            check(tasks,begin);
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
