//
//  main.cpp
//  二维数组查找
//
//  Created by 萧天牧 on 17/5/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool Find(int target, vector<vector<int> > array) {
    if(array.size() == 0)
        return false;
    int i = 0, j = array[0].size() - 1;
    while(i < array.size() && j >= 0){
        if(array[i][j] == target)
            return true;
        else if (array[i][j] > target)
            j--;
        else if (array[i][j] < target)
            i++;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> result = {{1,2},{3,4}};
    for (int i = 0; i < 4; i++) {
        cout << i<<" ";
        cout << Find(3, result)<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
