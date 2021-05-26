#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>

int main() {
    std::string name="";
    std::time_t t=std::time(nullptr);
    std::tm birthday=*std::localtime(&t);
    std::time_t n=std::time(nullptr);
    std::tm now=*std::localtime(&n);
    std::vector<std::tm> birthdays;
    std::vector<std::string> people;
    std::cout<<"Input your friends with their birthday"<<std::endl;
    while (true){

        std::cin>>name;
        if (name=="end"){
            break;
        }
        else{

            std::cin>>std::get_time(&birthday,"%y/%m/%d");
            if ((birthday.tm_mon>now.tm_mon)
                ||(birthday.tm_mon==now.tm_mon && birthday.tm_mday>=now.tm_mday)){
                people.push_back(name);
                birthdays.push_back(birthday);
                for (int i=0; i< birthdays.size(); i++){
                    if ((birthday.tm_mon<birthdays[i].tm_mon
                         ||(birthday.tm_mon==birthdays[i].tm_mon
                            && birthday.tm_mday < birthdays[i].tm_mday))){
                        people.erase(people.begin()+i);
                        birthdays.erase(birthdays.begin()+i);
                        i--;
                    }
                }

            }
        }
    }

    for (int i=0; i<birthdays.size(); i++){

        std::cout<<people[i]<<" "<<std::put_time(&birthdays[i], "%m/%d")<<std::endl;
        if (birthdays[i].tm_mon==now.tm_mon && birthdays[i].tm_mday==now.tm_mday){
            std::cout<<"Birthday is today!"<<std::endl;
        }
    }
    return 0;
}
