#include <iostream>
#include <ctime>
#include <iomanip>
#include<vector>
struct human{
    std::string name="unknown";
    std::time_t t=std::time(nullptr);
    std::tm birthday=*std::localtime(&t);
};
int main() {
    std::string name="";
    std::time_t n=std::time(nullptr);
    std::tm now=*std::localtime(&n);
    std::vector<human> birthdays;
    human B;
    std::cout<<"Input your friends with their birthday"<<std::endl;
    while (true){

        std::cin>>B.name;
        if (B.name=="end"){
            break;
        }
        else{

            std::cin>>std::get_time(&B.birthday,"%y/%m/%d");
            if ((B.birthday.tm_mon>now.tm_mon)
                ||(B.birthday.tm_mon==now.tm_mon && B.birthday.tm_mday>=now.tm_mday)){
                birthdays.push_back(B);
                for (int i=0; i< birthdays.size(); i++){
                    if ((B.birthday.tm_mon<birthdays[i].birthday.tm_mon
                         ||(B.birthday.tm_mon==birthdays[i].birthday.tm_mon
                            && B.birthday.tm_mday < birthdays[i].birthday.tm_mday))){
                        birthdays.erase(birthdays.begin()+i);
                        i--;
                    }
                }

            }
        }
    }

    for (int i=0; i<birthdays.size(); i++){

        std::cout<<birthdays[i].name<<" "<<std::put_time(&birthdays[i].birthday, "%m/%d")<<std::endl;
        if (birthdays[i].birthday.tm_mon==now.tm_mon && birthdays[i].birthday.tm_mday==now.tm_mday){
            std::cout<<"Birthday is today!"<<std::endl;
        }
    }
    return 0;
}
