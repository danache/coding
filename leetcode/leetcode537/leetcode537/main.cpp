//
//  main.cpp
//  leetcode537
//
//  Created by 萧天牧 on 17/8/30.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
pair<long, long> getres(string a){
    long real = 0, img = 0;
    bool shineg = false, xuneg = false;
    bool xu = false;
    for(auto c : a){
        if(c == '-'){
            if (xu){
                xuneg = true;
            }
            else
                shineg = true;
            continue;
        }
        if(c == '+'){
            xu = true;
            continue;
        }
        if(c == 'i')
            break;
        if(!xu){
            real = real * 10 + c -'0';
        }
        else{
            img = img * 10 + c -'0';
        }
    }
    if(shineg)
        real = -real;
    if(xuneg)
        img = -img;
    return make_pair(real, img);
}
string complexNumberMultiply(string a, string b) {
    pair<long, long> s1 = getres(a);
    pair<long, long> s2 = getres(b);
    long resfirst = s1.first * s2.first - s1.second * s2.second;
    long ressecond = s1.second * s2.first + s2.second * s1.first;
    string s = to_string(resfirst) + "+" +to_string(ressecond)+"i";
    return s;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    pair<long, long> s1 = getres("1+-1i");
    cout <<complexNumberMultiply("1+1i","1+1i")<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
