//
//  main.cpp
//  binaryTree
//
//  Created by dan on 16/9/2.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <cmath>
const int MAXN_N = 10000;
using namespace std;

int solve(int array[MAXN_N], int x, int len, bool &flag){
    int findnum = 0;
    int s = ceil(sqrt(2 * len));
    int i = -1;
    while(i != len -1){
        i += s;
        if (i >= len)
            i = len - 1;
        if(array[i] == x){
            findnum++;
            flag = true;
            return findnum;
        }
        else if(array[i] > x){
            while(array[i] > x && i > 0){
                i--;
                findnum++;
            }
            flag = (array[i] == x);
            return findnum;
        }
        s--;
    }
    flag = false;
    return findnum;
    
}

int main() {
    int num;
    int array[MAXN_N];
    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> array[i];
    }
    bool flag;
    int x;
    while(cin >> x){
        int pronums =solve(array, x, num, flag);
        cout << "search flag:  " << flag << "findnum: " << pronums<< endl;
    }
    
}


