#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::time_t n=std::time(nullptr);
    std::tm timer=*gmtime(&n);
    std::cout<<"Input time "<<std::endl;
    std::cin>>std::get_time(&timer,"%M:%S");
    int i=timer.tm_min*60+timer.tm_sec;
    n=std::time(nullptr);
    std::time_t b=0;
    int j=0;
    while (true){
        if (j<i){
            int k=j;
            b=std::time(nullptr)-n;
            std::tm now=*std::gmtime(&b);
            j=now.tm_min*60+now.tm_sec;
            if (j-k==1){

                if (now.tm_sec>timer.tm_sec) {
                    now.tm_min=timer.tm_min-now.tm_min-1;
                    now.tm_sec=60+timer.tm_sec-now.tm_sec;
                }
                else {
                    now.tm_min=timer.tm_min-now.tm_min;
                    now.tm_sec=timer.tm_sec-now.tm_sec;
                }
                std::cout<<std::put_time(&now,"%M:%S")<<std::endl;
            }
        }
        else if (j==i){
            std::cout<<"DING!DING!DING!"<<std::endl;
            break;
         }

      }




    return 0;
}
