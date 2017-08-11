//
//  main.cpp
//  导弹问题
//
//  Created by 萧天牧 on 17/4/22.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool pairSortFun( pair<int,int> elem1, pair<int,int> elem2 )
{
    return elem1.first > elem2.first;//or return elem1.first > elem2.second
}
sort( staticRectInfo.begin(), staticRectInfo.end(), pairSortFun);



int main(int argc, const char * argv[]) {
    vector<int> blood, attack, cost;
    
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        
    }
        
}
