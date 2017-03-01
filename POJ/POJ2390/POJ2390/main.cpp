//
//  main.cpp
//  POJ2390
//
//  Created by dan on 16/9/16.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdint.h>
using namespace std;
int main(int argc, const char * argv[]) {
    int32_t R, M ,Y;
    while(cin >> R >> M >> Y){
        double smallR = 1 + double(R/ 100.0);
        double sum = pow(smallR, Y);
        double res = M * sum;
        cout << int(res) << endl;
    }
}
