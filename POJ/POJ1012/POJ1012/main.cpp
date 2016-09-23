//
//  main.cpp
//  POJ1012
//
//  Created by dan on 16/9/9.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int k;
    while(cin >> k){
        if (k == 0)
            break;
        int res;
        int n = 1;
        while(true){
            int i = 2 * k;
            while(n % i > k || n % i == 0){
                cout << i << endl;
                i = i-n+i-1;
            }
            if (i %k == 0)
            {
                res = n;
                break;
            }
            n++;
        }
        cout << res << endl;
    }
}
