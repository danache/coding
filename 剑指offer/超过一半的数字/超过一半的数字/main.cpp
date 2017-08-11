//
//  main.cpp
//  超过一半的数字
//
//  Created by 萧天牧 on 17/5/16.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool judge(vector<int> numbers, int result){
    int count = 0;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == result)
            count++;
    }
    return (count << 1) > numbers.size();
}



int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size() == 0)
        return 0;
    int result = numbers[0];
    int count = 0;
    for(int i = 0; i < numbers.size(); i++){
        
        if(numbers[i] == result)
            count++;
        else
            count--;
        if(count == 0){
            result = numbers[i];
            count = 1;
        }
        
    }
    if(judge(numbers, result))
        return result;
    else
        return 0;
    
}
int main(int argc, const char * argv[]) {
    vector<int> number = {1,2,3,2,2,2,5,4,2};
    cout << MoreThanHalfNum_Solution(number)<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
