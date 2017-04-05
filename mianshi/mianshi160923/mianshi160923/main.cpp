//
//  main.cpp
//  mianshi160923
//
//  Created by dan on 16/9/23.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#define MAXN 1005
using namespace std;
class A{
    public:A(string name){cout << name;}};
int a[10000+5];
int b[10000+5];
int res[10000+5];
int main(){
    int m, n;
    while(cin >> m >> n){
        for(int i = 0; i < m; i++)
            cin >> a[i];
        for(int j = 0; j < n; j++)
            cin >> b[j];
    int lastexe = 0;
    for(int t = 0; t < m; t++){//444477
        if(a[t] > a [t - 1] + 1){
            int time = a[t] - 1;
            int thisexe = lastexe;
            while(b[thisexe] <= time && thisexe < n)
                thisexe++;
            for(int i = lastexe; i < thisexe; i++)
                res[i] = a[t - 1] + 1;
            lastexe = thisexe;
        }
    }
        for(int i = lastexe; i < n; i++){
        if(b[i] < a[m - 1] + 1)
            res[i] =a[m - 1] + 1;
        else
            res[i] = b[i];
        }
    for(int i = 0; i < n; i++)
        cout << res[i]<<endl;
    };
}
