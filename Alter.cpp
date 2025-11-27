#include <iostream>
#include <string>



int ListInsert_Binary(int x, int L[], int leng, int maxSize){
    int low = 0, high = leng - 1, mid;
    int pos = leng;

    if (leng >= maxSize) {
        std::cout << "Error: List is full!" << std::endl;
        return 0;
    }//检查是否满表

    while (low <= high) {
        mid = (low + high) / 2;
        if (L[mid] >= x) {
            pos = mid;
            high = mid - 1;
        } 
        else {low = mid + 1;}
    }// 二分查找插入位置

    for(int i = leng; i > pos; i--){
        L[i] = L[i - 1];
    }
    L[pos] = x;
    return 1;
}//第三问


int FindNumber(int x, int L[], int leng){
    int low = 0, mid, high = leng - 1, count = 0;
        while(low <= high){ //从这里开始定义折半查找
            count++;
            mid = (low + high ) / 2;
            std::cout << "第" << count << "次： 在[" << low << "--" << high << "]之间查找, 与" << L[mid] << "比较" << std::endl;
            if( x == L[mid]) return mid;
            else if ( x < L[mid]) {high = mid - 1;}
            else {low = mid + 1;}//折半查找
       }  std::cout << "查找失败 " << std::endl; //如果low > high 报错
        return -1;
}//查找完毕

int main(){
    int Lab12Array[]{0, 10, 20 ,30, 40, 50, 60, 70, 80, 90}; //定义第一问数组
    int length = sizeof(Lab12Array) / sizeof(Lab12Array[0]);
    int target = 0;
    std::cout << "Input the number u wanna find" << std::endl;
    std::cin >> target; //输入
    FindNumber(target, Lab12Array, length); //进行判断
    if(length != -1){
        std::cout << "Find! The number is: " << target << std::endl;
    }

    return 0;
}

