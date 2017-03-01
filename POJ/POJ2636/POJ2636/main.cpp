//
//  main.cpp
//  POJ2636
//
//  Created by dan on 16/9/17.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int ncase;
    cin >> ncase;
    int n;
    while(ncase--){
        cin >> n;
        int sum =  1 - n;
        int tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << endl;
        
    }
    
    
}
