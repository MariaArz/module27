#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::time_t n=std::time(nullptr);
    std::tm timer=*std::localtime(&n);
    std::cin>>std::get_time(&timer,"%M:%S");
    while (timer.tm_min*60+timer.tm_sec > 0){
        std::time_t n=std::time(nullptr);
        std::time_t a=std::time(nullptr);
        if (std::difftime(a,n)==1){
            timer.tm_min*60+timer.tm_sec--;
            std::cout<<std::put_time(&timer,"%M:%S")<<std::endl;
        }
    }
    if (timer.tm_min*60+timer.tm_sec == 0){
        std::cout<<"DING!DING!DING!"<<std::endl;
    }
    return 0;
}
