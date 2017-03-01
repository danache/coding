//
//  main.cpp
//  POJ1658
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int a[6];
int main(int argc, const char * argv[]) {
    int casenum;
    cin >> casenum;
    while(casenum--){
        for(int i = 0; i < 4; i++){
            cin >> a[i];
        }
        if(a[3] - a[2] == a[2] - a[1] && a[3] - a[2] == a[1] - a[0]){
            a[4] = 2 * a[3] - a[2];
        }
        else{
            a[4] = a[3] * a[3] / a[2];
        }
        for (int i = 0; i < 5; i++)
            cout << a[i] <<" ";
        cout << endl;
    }
}

