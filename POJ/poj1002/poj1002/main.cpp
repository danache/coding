//
//  main.cpp
//  poj1002
//
//  Created by dan on 16/9/1.
//  Copyright © 2016年 dan. All rights reserved.
//
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 10000000
class event{
public:
    string p;
    int num;
    
    event(string _p = ""){
        p = _p;
        num = 0;
    }
    
    const void add(){
        num++;
    }
};
char transion(char s){
    int num ;
    switch (s) {
        case 'A':
        case 'B':
        case 'C':
            num = 2;
            break;
        case 'D':
        case 'E':
        case 'F':
            num = 3;
            break;
        case 'G':
        case 'H':
        case 'I':
            num = 4;
            break;
        case 'J':
        case 'K':
        case 'L':
            num = 5;
            break;
        case 'M':
        case 'N':
        case 'O':
            num = 6;
            break;
        case 'P':
        case 'R':
        case 'S':
            num = 7;
            break;
        case 'T':
        case 'U':
        case 'V':
            num = 8;
            break;
        case 'W':
        case 'X':
        case 'Y':
            num = 9;
            break;
            
        default:
            break;
    }
    return num + '0';
}


int getTrans(string S){
    int res = 0;
    for (int i = 0;i < S.length(); i++){
        if(isdigit(S[i])){
            res  = res * 10 + S[i] - '0';
        }
        else if (('A' <=S[i] && S[i] <= 'P') ||('R' <=S[i] && S[i] <= 'Z') )
        {
            res =   res * 10 + transion(S[i]);
        }
    }
    return res;
}
int main() {
    int ans[MAXN] = {0};
    memset(ans, 0, sizeof(ans));
    int k;
    scanf("%d", &k);
    string s;
    while(k--){
        scanf("%s", &s);
        int tmp = getTrans(s);

        ans[tmp]++;
    }
    for(int i = 0;i < MAXN; i++){
        if (ans[i] > 1)
            printf("%03d-%04d :%d/n",i / 10000, i % 10000, ans[i]);
    }
    
}
