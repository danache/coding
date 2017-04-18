//
//  main.cpp
//  串匹配
//
//  Created by 萧天牧 on 17/4/6.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
int match1(char * P, char *T){
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j = 0;
    while(i < n && j < m){
        if (P[i] == T[j]){
            i++;
            j++;
        }
        else{
            i -= j - 1;
            j = 0;
        }
    }
    return i - j;
}

int match2(char *P, char *T){
    size_t n = strlen(T), i = 0;
    size_t m = strlen(P), j;
    for(i = 0; i < n - m + 1; i++){
        for (j = 0; j < m; j++){
            if(T[i + j] != P[j])
                break;
        }
        if (j >= m)
            break;
    }
    return i;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
