//
//  main.cpp
//  POJ1080
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//
/*********************************************
 
 本题利用的是变体的LCS，一开始我想麻烦了。其实在更新lcs数组的时候直接利用value就可以。此外还学会了用map来表示dictionary，
 最后的bug在于string从0开始。。以后注意了。
 
 ********************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#define MAXN 110

using namespace std;

int score[5][5] = {
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}};

int source[MAXN][MAXN];
int c[MAXN][MAXN];
map <char, int> dictionary;
void lcsLength(char* x, int xlen,  char* y ,int ylen){
    int m = xlen;
    int n = ylen;
    c[0][0] = 0;
    for (int i = 1; i <= m; i++){
        c[i][0] = score[dictionary[x[i]]][dictionary['-']] + c[i - 1][0];
    }
    for (int j = 1; j <= n; j++){
        c[0][j] = score[dictionary['-']][dictionary[y[j]]] + c[0][j - 1];
    }
    for(int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            
            c[i][j] = max(c[i - 1][j - 1] +  score[dictionary[x[i]]][dictionary[y[j]]], c[i - 1][j] + score[dictionary[x[i]]][dictionary['-']]);
            c[i][j] = max(c[i][j], c[i][j - 1] + score[dictionary['-']][dictionary[y[j]]]);
            
        }
    }
    cout <<  c[m][n] << endl;;
}

int main(int argc, const char * argv[]) {
    dictionary['A'] = 0, dictionary['C'] = 1;
    dictionary['G'] = 2, dictionary['T'] = 3,dictionary['-'] = 4;
    int ncase;
    cin >> ncase;
    char a[MAXN], b[MAXN];
    int alen, blen;
    while(ncase --){
        scanf("%d %s", &alen, a+1);
         scanf("%d %s", &blen, b+1);

        lcsLength(a, alen, b, blen);
        
    }
    
}
