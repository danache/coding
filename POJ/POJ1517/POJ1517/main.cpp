//
//  main.cpp
//  POJ1517
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
float getFactorial(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return n * getFactorial(n - 1);
}

void getE(int n){
    float sum = 0;
    for(int i = 0;i <= n ;i++){
        sum += (1 / getFactorial(i));
    }
    cout << n << " " << sum << endl;
}
int main(int argc, const char * argv[]) {
    for(int i = 0; i < 10; i++)
        getE(i);
}
