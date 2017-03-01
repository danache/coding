//
//  main.cpp
//  shuchuan
//
//  Created by dan on 16/9/22.
//  Copyright © 2016年 dan. All rights reserved.


#include <iostream>
#define MAXN 105
using namespace std;

string a[MAXN];

bool compares(string a, string b){
    int alen = a.length();
    int blen = b.length();
    int minlen = min(alen, blen);
    for (int i = 0; i < minlen; i++){
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    if (alen == minlen){
        return a[alen - 1] > b[0];
    }
    else
        return b[blen - 1] > a[0];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    
    while(cin >> N){
        
        for (int i = 0; i < N ; i++)
            cin >>a[i];
        
        sort(a, a + N,compares);
        string tmp = "";
        for (int i = 0; i < N; i++){
            tmp += a[i];
        }
        cout << tmp << endl;
    }
}
