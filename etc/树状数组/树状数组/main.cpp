//
//  main.cpp
//  树状数组
//
//  Created by dan on 16/10/19.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;

int lowbit(k){
    return k & ( -k);
}
int main(int argc, const char * argv[]) {
    int a = 4;
    cout << (4 & -4) << endl;
}
