//
//  main.cpp
//  test
//
//  Created by dan on 16/10/4.
//  Copyright © 2016年 dan. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){

        bitset<32> aint;
        bitset<32> bint;
        cin >> aint >> bint;
        int alen = aint.size();
        int blen = bint.size();
        
        if (alen > blen){
            int num = alen - blen;
            for(int i = 0; i < blen;i++){
                aint[i + num] = aint[i + num] ^ (bint[i]);
            }
            cout << aint.to_ulong() << endl;
        }
        else{
            int num = blen - alen;
            for(int i = 0; i < alen;i++){
                bint[i + num] = bint[i + num] ^ (aint[i]);
            }
            cout << bint.to_ulong() << endl;
        }
        


    }
    return 0;
}
