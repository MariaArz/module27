#include <iostream>
#include <ctime>
#include <iomanip>
#include<map>

enum {
    ON,
    OFF,
    DO_SMTH,
    DO_SMTH_OTHER
};
void check(int& process,std::map<std::string,std::time_t>& tasks){
    std::string task_current="";

    if (process & ON){
        process&= ~ON;
        task_current="on";
    }
    else if (process & OFF){
        process&= ~OFF;
        task_current="off";
    }
    else if (process & DO_SMTH){
        process&= ~DO_SMTH;
        task_current="do_smth";
    }
    else if (process & DO_SMTH_OTHER){
        process&= ~DO_SMTH_OTHER;
        task_current="do_smth_other";
    }
    std::time_t end=std::time(nullptr);
    if (task_current!=""){
        std::cout<<task_current<<" end in "<<std::put_time(std::localtime(&end),"%H:%M:%S")<<std::endl;
        tasks[task_current]=(std::time_t)std::difftime(end,tasks[task_current]);
    }
}
void start(std::string task, int& process,  std::map<std::string,std::time_t>& tasks){
    if (task=="on"){
        process|=ON;
    }
    else if (task=="off"){
        process|=OFF;
    }
    else if (task=="do_smth"){
        process|=DO_SMTH;
    }
    else if (task=="do_smth_other"){
        process|=DO_SMTH_OTHER;
    }
    std::time_t begin=std::time(nullptr);
    std::cout<<task<<" begin in "<<std::put_time(std::localtime(&begin),"%H:%M:%S")<<std::endl;
    tasks.insert(std::pair<std::string,std::time_t>(task,begin));
}

void current(int& process,std::map<std::string,std::time_t>& tasks){
    std::string task_current="";

    if (process & ON){
        task_current="on";
    }
    else if (process & OFF){
        task_current="off";
    }
    else if (process & DO_SMTH){
        task_current="do_smth";
    }
    else if (process & DO_SMTH_OTHER){
        task_current="do_smth_other";
    }
    for (std::map<std::string,std::time_t>::iterator it=tasks.begin();
        it!=tasks.end(); it++){
        if (it->first!=task_current){
            std::cout<<it->first<<" "<<std::put_time( std::localtime(&it->second),"%H:%M:%S")<<std::endl;

        }

    }
    if (task_current!="") {
        std::cout << "Doing "<< task_current << std::endl;
    }
}
int main() {
    int process=0;
    std::string  command, task;
    std::map<std::string,std::time_t> tasks;
    for (;;){
        std::cout<<"Input command"<<std::endl;
        std::cin>>command;
        if (command=="begin"){
            std::cout<<"Input task"<<std::endl;
            std::cin>>task;
            check(process,tasks);
            start(task,process,tasks);
        }
        else if (command=="end"){
            check(process,tasks);
        }
        else if (command=="status"){
            current(process,tasks);
        }
        else if (command== "exit"){
            break;
        }
    }

    return 0;
}
