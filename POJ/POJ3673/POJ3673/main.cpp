//
//  main.cpp
//  POJ3673
//
//  Created by dan on 16/9/15.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAXN 12
char a[MAXN];
char b[MAXN];

int main(int argc, const char * argv[]) {
    cin >>a >> b;
    int index_a, index_b;
    for(index_a = 0; index_a < 11 && a[index_a] != '\0'; index_a++)
        ;
    for(index_b = 0; index_b < 11 && b[index_b] != '\0'; index_b++)
        ;
    int sum = 0;
    for (int i = 0;i < index_a; i++){
        for (int j = 0; j < index_b; j++){
            sum += (a[i] - '0') * (b[j] - '0');
        }
    }
    cout << sum << endl;
}
