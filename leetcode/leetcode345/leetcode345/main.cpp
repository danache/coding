//
//  main.cpp
//  leetcode345
//
//  Created by 萧天牧 on 17/8/9.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool isin(char c){
    if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
        return true;
    return false;
}
string reverseVowels(string s) {
    if(s.empty())
        return s;
    int i = 0, j = s.size() - 1;
    while(i < j){
        while(i < s.size() &&!isin(s[i]))
              i++;
        while(j >= 0 && !isin(s[j]))
            j--;
        if (i >= j)
            break;
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << reverseVowels("leetcode");
    return 0;
}
