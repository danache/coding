//
//  main.cpp
//  leetcode275
//
//  Created by 萧天牧 on 17/8/2.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int hIndex(vector<int>& citations) {int len = citations.size(),maxH = 0;
    for (int i = len - 1; i >= 0; --i)
    {
        int h = len - i;
        if (citations[i] >= h && h > maxH)
        {
            maxH = h;
        }
        else{
            break;
        }
    }//for
    return maxH;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
