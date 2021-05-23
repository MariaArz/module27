#include <iostream>
#include <ctime>
#include <iomanip>
#include<map>

int main() {
    std::string name="";
    std::time_t t=std::time(nullptr);
    std::tm birthday=*std::localtime(&t);
    std::time_t n=std::time(nullptr);
    std::tm now=*std::localtime(&n);
    std::map<std::string, std::tm> people;
    people.insert(std::pair<std::string, std::tm>(name,now));
    std::cout<<"Input your friends with their birthday"<<std::endl;
    while (name!="end"){
        std::cin>>name;
        if (name=="end"){
            break;
        }
            std::cin>>std::get_time(&birthday,"%y/%m/%d");
            if ((birthday.tm_mon>now.tm_mon)
                ||(birthday.tm_mon==now.tm_mon && birthday.tm_mday>=now.tm_mday)){
                while (!people.empty()
                    && ((birthday.tm_mon!=people.begin()->second.tm_mon
                        && birthday.tm_mday != people.begin()->second.tm_mday))){
                    if (people.begin()->first==""
                        || (birthday.tm_mon<people.begin()->second.tm_mon
                            ||(birthday.tm_mon==people.begin()->second.tm_mon
                               && birthday.tm_mday < people.begin()->second.tm_mday))){
                        people.erase(people.begin());
                    }
                }
                people.insert(std::pair<std::string, std::tm>(name,birthday));
            }

    }

    for (std::map<std::string, std::tm>::iterator it=people.begin(); it!=people.end(); it++){

        std::cout<<it->first<<" "<<std::put_time(&it->second, "%m/%d")<<std::endl;
        if (it->second.tm_mon==now.tm_mon && it->second.tm_mday==now.tm_mday){
            std::cout<<"Birthday is today!"<<std::endl;
        }
    }
    return 0;
}
