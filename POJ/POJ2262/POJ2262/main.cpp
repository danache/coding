//
//  main.cpp
//  POJ2262
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1000000;
bool a[MAXN];
void getnum(){
    a[0] = a[1] = false;
    a[2] = true;
    a[3] = true;
    for (int i = 2; i < MAXN; i++){
        for(int j = 2; j * i < MAXN; j++){
            a[i * j] = false;
        }
    }
}
int main(int argc, const char * argv[]) {
    memset(a, true, sizeof(a));
    getnum();
    int num;
    while(cin >> num){
        if (num == 0)
            break;
        int tail = num;
        int front = 0;
        while(true){
            if(tail == front)
                cout <<	"Goldbach's conjecture is wrong." << endl;
            if (!a[tail])
            {
                tail--;
                continue;
            }
            front = num - tail;
            if(a[front]){
                cout << num <<" = " << front << " + " << tail <<endl;
                break;
            }
            else
                tail--;
        }
        
        
    }
}
