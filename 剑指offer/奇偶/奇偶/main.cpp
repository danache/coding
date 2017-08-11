//
//  main.cpp
//  奇偶
//
//  Created by 萧天牧 on 17/5/14.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void reOrderArray(vector<int> &array) {
    vector<int> tmp;
    for(vector<int>::iterator iter=array.begin(); iter!=array.end();){
        if(0 == (*iter)%2){
            tmp.push_back(*iter);
            remove(iter);
        }
    }
    
}
int main(int argc, const char * argv[]) {
    vector<int> a ={1,2,3,4,5};
    reOrderArray(a);
    for(int i = 0; i < a.size(); i++)
        cout << a[i];
    std::cout << "Hello, World!\n";
    return 0;
}
