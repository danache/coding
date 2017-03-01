//
//  main.cpp
//  POJ2388
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10000;
int a[MAXN];
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[n/2] << endl;
    
}
