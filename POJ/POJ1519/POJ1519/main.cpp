//
//  main.cpp
//  POJ1519
//
//  Created by dan on 16/9/16.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#define MAXN 10000
using namespace std;
void getNum(char *p){
    int index = 0;
    int sum = 0;
    while(p[index] != '\0')
        index++;
    for (int i = 0; i < index; i++){
        sum += p[i] - '0';
    }
    int tmp = sum % 9 ;
    if (tmp == 0)
        cout << "9" << endl;
    else
        cout << tmp << endl;
}
char p[MAXN];
int main(int argc, const char * argv[]) {
    while(cin >> p){
        if (p[0] == '0')
            break;
        getNum(p);
    }
}

