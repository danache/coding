//
//  main.cpp
//  POJ2301
//
//  Created by dan on 16/9/16.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int ncase;
    cin >> ncase;
    int a, b;
    while(ncase--){
        cin >> a >> b;
        if(a < b || (a - b ) % 2 != 0)
            cout << "impossible" << endl;
        else
            cout << (a + b) / 2 <<" " << (a - b) / 2 << endl;
    }
}
