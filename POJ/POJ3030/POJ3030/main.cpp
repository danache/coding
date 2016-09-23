//
//  main.cpp
//  POJ3030
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int  ncase;
    
    cin >> ncase;
    long r, e, c;
    while(ncase--){
        cin >> r >> e >> c;
        long tmp = e - r - c;
        if(tmp > 0)
            cout << "advertise" << endl;
        else if (tmp == 0)
            cout << "does not matter" << endl;
        else
            cout << "do not advertise" << endl;
    }
}
