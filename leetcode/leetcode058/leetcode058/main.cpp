//
//  main.cpp
//  leetcode058
//
//  Created by 萧天牧 on 17/7/25.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int lengthOfLastWord(string s) {
    int num = 0;
    bool flag = false;
    for(auto i : s){
        if(i != ' '){
            if(flag){
                num = 0;
                flag = false;
            }
            num++;
            continue;
        }
        else{
            flag = true;
        }
    }
    return num;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << lengthOfLastWord("Hello world");
    std::cout << lengthOfLastWord("     ");
    
    return 0;
}
