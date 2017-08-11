//
//  main.cpp
//  空格替换
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
void replaceSpace(char *str,int length) {
    if(str == NULL || length <= 0)
        return;
    int originlen = 0, newlen = 0;
    char *p1 = str;
    while(*p1 != '\0'){
        originlen++;
        newlen++;
        if(*p1 == ' '){
            newlen += 2;
        }
        p1++;
    }
    int i = 0;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char *p = "i am happy";
    replaceSpace(p, 50);
    for(int i = 0; i< 50; i++)
        cout << p[i];
    std::cout << "Hello, World!\n";
    return 0;
}
