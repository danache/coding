//
//  main.cpp
//  leetcode401
//
//  Created by 萧天牧 on 17/8/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void getres(int beginNum, int leftnum, int nowselect, vector<int>& res){
    if(leftnum == 0)
        res.push_back(nowselect);
    else{
        for(int i = beginNum; i < 10; i++)
            getres(i + 1, leftnum - 1, nowselect + (1 << (9 - i)), res);
    }
}
vector<string> readBinaryWatch(int num) {
    int bk[] {8, 4, 2, 1, 32, 16, 8, 4 ,2 ,1};
    vector<int> res;
    getres(0, num, 0, res);
    vector<string> s;
    for(auto n : res){
        int i = 0 ;
        int hour = 0;
        int minute = 0;
        while(n){
            if(i < 4)
                hour += (n & 1)*bk[i];
            else
                minute += (n & 1)*bk[i];
            i++;
            n >>= 1;
        }
        string min;
        if (hour >= 12 || minute >= 60)
            continue;
        if(minute>= 0 && minute <=9)
            min = "0";
        string tmp = to_string(hour)+":"+min+to_string(minute);
        s.push_back(tmp);
    }
    
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    readBinaryWatch(2);
    return 0;
}
