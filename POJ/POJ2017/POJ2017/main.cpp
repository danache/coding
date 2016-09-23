//
//  main.cpp
//  POJ2017
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    while(cin >> n){
        if ( n == -1)
            break;
        int speed = 0, last_hour = 0, all_hour;
        int miles = 0;
        while(n--){
            cin >> speed >> all_hour;
            miles += speed * (all_hour - last_hour);
            last_hour = all_hour;
        }
        cout << miles << " miles" << endl;
    }
    
}
