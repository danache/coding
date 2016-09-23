//
//  main.cpp
//  POJ3980
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int mod(int n, int m){
    int i = 1;
    while(true){
        if (n >= i *(m) && n <= (i + 1)* m)
            return n - i * m;
        else
            i++;
    }
}
int main(int argc, const char * argv[]) {
    int a, b;
    while(!cin.eof()){
        cin >>a >> b;
        cout << mod(a, b) << endl;
    }
}
