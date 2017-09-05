//
//  main.cpp
//  leetcode476
//
//  Created by 萧天牧 on 17/8/24.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int findComplement(int num) {
    long res = 0;
    int i = 0;
    while(num){
        if(!(num & 1))
            res += 1 << i;
        i++;
        num >>= 1;
    }
    return res;
}
int main(int argc, const char * argv[]) {
    cout << findComplement(1)<<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
