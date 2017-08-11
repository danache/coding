//
//  main.cpp
//  leetcode313
//
//  Created by 萧天牧 on 17/8/8.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int nthSuperUglyNumber(int n, vector<int>& primes) {
    if (n == 0)
        return 0;
    if ( n == 1)
        return 1;
    vector<int> res(n+1,0);
    vector<int> back(primes.size()+1,0);
    res[0] = 1;
    for(int i = 1; i <= n; i++){
        int32_t minNum = INT_MAX;
        int pos = -1;
        for(int j = 0; j < primes.size(); j++){
            int tmp1 =primes[j] ;
            int tmp2 = res[back[j]] ;
            
            if(primes[j] * res[back[j]] < minNum){
                minNum = primes[j] * res[back[j]];
                pos = j;
            }
        }
        res[i] = minNum;
        for(int k = 0; k < primes.size(); k++){
            if(primes[k] * res[back[k]] == minNum)
            back[k]++;
        }
        
    }
    return res[n -1];
}

int nthUglyNumber(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    vector<int> vec(n);
    vec[0] =1;
    int t2 = 0, t3 = 0, t5 = 0;
    for(int i = 1; i < n; i++){
        int tmp = min(vec[t2] * 2, vec[t3] * 7);
        int minx = min(tmp, vec[t5] * 13);
        vec[i] = minx;
        if(minx == 2 * vec[t2])
            t2++;
        if(minx == 7 * vec[t3])
            t3++;
        if(minx == 13 * vec[t5])
            t5++;
    }
    return vec[n - 1];
}
int main(int argc, const char * argv[]) {
    vector<int> a = {2,5,7,11,13,17,23,29,43,53};
  
    cout << nthSuperUglyNumber(10,a);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
