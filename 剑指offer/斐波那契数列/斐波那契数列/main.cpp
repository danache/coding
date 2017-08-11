//
//  main.cpp
//  斐波那契数列
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
int Fibonacci(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    int num1 = 1, num2 = 1;
    int res = 0;
    for(int i = 0; i < n - 1; i++){
        int tmp = num1;
        num1 = num2;
        res = num1 + tmp;
        num2 = res;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    for(int i = 1; i < 10; i++)
        cout << Fibonacci(i)<<endl;
}
