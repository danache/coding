//
//  main.cpp
//  数组中重复的数字
//
//  Created by 萧天牧 on 17/5/7.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
using namespace std;
bool duplicate(int numbers[], int length, int* duplication) {
    if (numbers == NULL || length <= 0)
        return false;
    for(int i = 0; i < length; i++)
        if (numbers[i] < 0 || numbers[i] >= length)
            return false;
    for(int i = 0; i < length; i++){
        while (numbers[i] != i) {
            if(numbers[numbers[i]] == numbers[i]){
                *duplication = numbers[i];
                return true;
            }
            swap(numbers[i],numbers[numbers[i]]);
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int a[] = {0,1,2};
    int b[] = {0,1,2,3};
    int c[] = {0,1,1,3};
    int d[] = {0,1,2,4};
    int e[] = {0,1,2,-1};
    int *tmp = {};
    cout << duplicate(a, 3, tmp)<<endl;
    cout << duplicate(b, 4, tmp)<<endl;
    cout << duplicate(c, 4, tmp)<<endl;
    cout << duplicate(d, 4, tmp)<<endl;
    cout << duplicate(e, 4, tmp)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
