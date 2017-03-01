//
//  main.cpp
//  POJ3094
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    while(getline(cin, s)){
        if (s == "#")
            break;
        int index;
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            if( 'A'<= s[i] && s[i] <= 'Z')
                index = s[i] - 'A' + 1;
            else
                index = 0;
            
            sum += index * (i + 1);
        }
        cout << sum << endl;
    }
}
