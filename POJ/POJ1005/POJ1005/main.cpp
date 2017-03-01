//
//  main.cpp
//  POJ1005
//
//  Created by dan on 16/9/8.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.1415926;
int main(int argc, const char * argv[]) {
    int n;
    float x, y;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x ;
        cin >> y;
        float r2 = pow(x, 2) + pow(y, 2);
        int year = 1;
        while(100*year < r2 * pi ){
            year++;
        }
        cout << "Property "<< (i + 1) <<": This property will begin eroding in year "<< year << "." <<endl;
    }
    cout << "END OF OUTPUT." <<endl;
}
