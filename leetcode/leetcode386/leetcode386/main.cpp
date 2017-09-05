//
//  main.cpp
//  leetcode386
//
//  Created by 萧天牧 on 17/8/11.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void generate(vector<int> &vec, int nownum, int target){
    if (nownum > target)
        return;
    bool flag = true;
    if(nownum != 0){
        vec.push_back(nownum);
        for(int i = 0; i <= 9; i++){
            generate(vec, nownum*10 + i, target);
        }
    }
    else{
        for(int i = 1; i <= 9; i++){
            generate(vec, nownum*10 + i, target);
        }
    }
}
vector<int> lexicalOrder(int n) {
    int nownum = 0;
    vector<int> vec;
    generate(vec, nownum, n);
    return vec;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = lexicalOrder(13);
    for(auto s :a)
        cout << s << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
