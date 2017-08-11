//
//  main.cpp
//  leetcode279
//
//  Created by 萧天牧 on 17/7/4.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
//int getRes(int n, map<int, int>& mp,map<int,int>& flag){
//    if(mp.count(n) == 1)
//        return mp[n];
//    int tmp = int(sqrt(n));
//    int minval = +999999;
//    for(int i = tmp; i>= 1; i--){
//        int res = 0;
//        if(flag[n - i * i] == 1)
//            res = mp[n - i * i]+1;
//        else
//            res = getRes(n - i * i, mp,flag)+1;
//        minval = min(res, minval);
//    }
//    mp[n] = minval;
//    flag[n] = 1;
//    return mp[n];
//}
//int numSquares(int n) {
//    map<int, int> mp;
//    map<int, int> flag;
//    int tmp = int(sqrt(n));
//    int minVal = 999999;
//    for(int i = 1; i <= tmp; i++)
//        mp[i * i] = 1;
//    
//    for(int i = tmp; i >= 1; i--){
//        int square = i * i;
//        if (n == square)
//            return 1;
//        minVal = min(getRes(n - square, mp,flag)+1, minVal);
//    }
//    return minVal;
//}
int numSquares(int n) {
    vector<int> vec(n + 1,0);
    for(int i = 1; i < n; i++){
        int sq = int(sqrt(i));
        if (pow(sq, 2) == i)
            vec[i] = 1;
        else{
            int minval = 9999;
            for(int j = sq; j >= 0; j--){
                int a =vec[pow(j, 2)] ;
                int b =vec[i - pow(sq, 2)];
                minval = min(a+ b,minval);
            }
            vec[i] = minval;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //for(int i = 1 ;  i < 16; i++)
        std::cout  << " " << numSquares(12)<<endl;
    return 0;
}
