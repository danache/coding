//
//  main.cpp
//  POJ2024
//
//  Created by dan on 16/9/12.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x < y)
            cout << "NO BRAINS" << endl;
        else
            cout << "MMM BRAINS"<< endl;
    }
}
