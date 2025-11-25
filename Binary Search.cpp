#include <iostream>
#include <new> 
using namespace std;

int BiList(DataType L[], DataType item, int len){
    int low = 0, high = len - 1, mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(item == L[mid]) return mid;
        else if (item < L[mid]) high = mid -1;
        else low = mid + 1;
    }
    return -1;
}
