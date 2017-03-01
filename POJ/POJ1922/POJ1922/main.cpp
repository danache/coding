//
//  main.cpp
//  POJ1922
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 10001


int main(int argc, const char * argv[]) {
    int ncase;
    int speed, start;
    while(cin >> ncase){
        if (ncase == 0)
            break;
        float mintime = 99999;
        for (int i = 0; i < ncase; i++){
            cin >> speed >> start;
            if(start >= 0){
                float getTime = float(4500 * 3.6 / speed) + start;
                mintime = min(mintime, getTime);
            }
        }
        cout << ceil(mintime) << endl;
    }
}