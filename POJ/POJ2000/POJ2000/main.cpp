//
//  main.cpp
//  POJ2000
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int getn(int num){
    int i = 1;
    while(true){
        int tmp1 = i * (i - 1);
        int tmp2 = i * (i + 1);
        int n2 = 2 * num;
        if(tmp1 < n2 && tmp2 >= n2)
            return i;
        i++;
    }
}
int getpow(int n){
    int res = 0;
    for (int i = 1; i < n; i++)
        res += i * i;
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    while(cin >> num){
        if (num == 0)
            break;
        int n = getn(num);
        int res = getpow(n);
        res += (num -(n * (n - 1) )/ 2) * n;
        cout << num << " " << res << endl;
        
    }
    return 0;
}
