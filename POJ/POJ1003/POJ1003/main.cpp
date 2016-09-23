//
//  main.cpp
//  POJ1003
//
//  Created by dan on 16/9/8.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;

int getMinCard(float num){
    float i = 2;
    float sum = 0;
    while(sum <= num){
        sum += 1 / i;
        i++;
    }
    return i-2;
}
int main(int argc, const char * argv[]) {
    float num;
    while(cin >> num){
        if (num == 0.00){
            break;
        }
        cout <<getMinCard(num) <<" card(s)" << endl;
    }
}
