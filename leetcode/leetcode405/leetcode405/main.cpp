//
//  main.cpp
//  leetcode405
//
//  Created by 萧天牧 on 17/8/14.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//string getc(int num){
//    if(0<= num  && num <= 9)
//        return to_string(num);
//    char c =((num -10) + 'a');
//    string tmp = " ";
//    tmp[0] = c;
//    return tmp;
//    
//}
//string toHex(int num) {
//    if(num >=0){
//        string s = "";
//        while(num){
//            int a = num % 16;
//            num /= 16;
//            s += getc(a);
//        }
//        reverse(s.begin(), s.end());
//        return s;
//    }
//    else{
//        string s = "";
//        int tmp = ~num + 1;
//        cout << tmp << endl;
//        while(tmp){
//            int a = tmp% 16;
//            tmp /= 16;
//            s += getc(a);
//        }
//        reverse(s.begin(), s.end());
//        return s;
//    }
//}

//////////////////******************/////////////对于2的^n次幂，直接右移就可以
string toHex(int num) {
    string s;
    if(num == 0)
        return "0";
    char p[2] = {" "};
    char dict[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    
    for(int i = 0; i < 8; i++){
        p[0] = dict[num & 15];
        s += string(p);
        num >>= 4;
    }
    reverse(s.begin(), s.end());
    while(s.size() > 1 && s[0] == '0')
        s = s.substr(1);
    return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << toHex(26)<<endl;
    return 0;
}
