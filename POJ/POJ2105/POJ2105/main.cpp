//
//  main.cpp
//  POJ2105
//
//  Created by dan on 16/9/14.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int ip[5];
void getIP(string p){
    string res;
    int num;
    for(int i = 1; i <= 4; i++){
        num = 0;
        int carry = 7;
        for(int j = (i - 1) * 8; j <= i * 8 - 1; j++){
            num += pow(2.0, carry) * (p[j] -'0');
            
            carry--;
        }
        ip[i] = num;
    }
    
}
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string s;
    while(n--){
        cin >> s;
        getIP(s);
        for(int i = 1; i < 5; i++)
        {
            cout << ip[i];
            if(i != 4){
                cout <<".";
            }
            else
                cout << endl;
        }
    }
}
