//
//  main.cpp
//  POJ1007
//
//  Created by dan on 16/9/9.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 100;

struct gene{
    string atcg;
    int reve;
    gene(){
        atcg = "";
        reve = 0;
    }
};
gene ATCG[MAXN];
int getReverse(string atcg){
    int res = 0;
    for (int i = 0;i < atcg.length();i++){
        for(int j = i + 1; j < atcg.length(); j++){
            if(atcg[j] < atcg[i])
                res++;
        }
    }
    return res;
}
bool comless(const gene &a , const gene &b )
{
    return a.reve < b.reve;
}

int main(int argc, const char * argv[]) {
    int len, n;
    cin >> len >> n;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        ATCG[i].atcg = tmp;
        int re = getReverse(ATCG[i].atcg);
        ATCG[i].reve =re;
    }
    sort(ATCG, ATCG + n,comless);
    for (int i = 0; i < n; i++){
        string tmp = ATCG[i].atcg;
        cout << tmp << endl;;
    }
    return 0;
}
