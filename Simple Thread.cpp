#include <iostream>

int main(){
    int i = 0;
    while(true){
        if(i == 0){std::cout <<"Thread_1"<< std::endl;}
        else if(i == 1){std::cout <<"Thread_2"<< std::endl;}
        else{std::cout <<"Thread_3"<< std::endl;}

        i = (i + 1) % 3;
        
    }
    return 0;
}