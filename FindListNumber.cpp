#include <iostream>
#include <string>



int FindNumber(int x, const int L[], int leng){
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
    const int Lab12Array[]{0, 10, 20 ,30, 40, 50, 60, 70, 80, 90}; //定义第一问数组
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

