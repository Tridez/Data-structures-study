#include <iostream>

int i = 0;

void wait(){
    while(i <= 0)
    i = i - 1;
}

void signal(){
    i = i + 1;
}