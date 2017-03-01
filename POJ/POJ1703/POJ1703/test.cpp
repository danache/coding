//
//  test.cpp
//  POJ1703
//
//  Created by dan on 16/9/23.
//  Copyright © 2016年 dan. All rights reserved.
//

#include "test.hpp"



/*************************************************************************
 
 > File Name: example_unionset.cpp
 
 > Author: AOA
 
 > Mail: huguangchaoren@163.com
 
 > Created Time: 三  9/16 22:52:55 2015
 
 ************************************************************************/



#include <iostream>

#define MAX_M 1000

using namespace std;



struct relation {
    
    int32_t from, to, rel;
    
};



struct unionset_node {
    
    int32_t father, rel;
    
};



int32_t relation1[MAX_M + 5][MAX_M + 5] = {0};



unionset_node relation2[MAX_M + 5];



bool solve1(relation rel, int32_t M) {
    
    int32_t f = rel.from, t = rel.to, r = rel.rel;
    
    if (relation1[f][t] != -1 && relation1[f][t] != r) {
        
        return true;
        
    }
    
    relation1[f][t] = r;
    
    for (int32_t i = 1; i <= M; i++) {
        
        if (relation1[i][t] != -1) {
            
            relation1[i][f] = relation1[f][t] ^ relation1[i][t];
            
            relation1[f][i] = relation1[i][f];
            
        }
        
        if (relation1[i][f] != -1) {
            
            relation1[i][t] = relation1[f][t] ^ relation1[i][f];
            
            relation1[t][i] = relation1[i][t];
            
        }
        
    }
    
    return false;
    
}



int32_t get_root2_3(int32_t ind, int32_t &r, int32_t mod_num) {
    
    int32_t root_index;
    
    if (relation2[ind].father != ind) {
        
        root_index = get_root2_3(relation2[ind].father, r, mod_num);
        
        r += relation2[ind].rel;
        
        relation2[ind].father = root_index;
        
        relation2[ind].rel = r % mod_num;
        
        return root_index;
        
    }
    
    return ind;
    
}



bool solve2_3(relation rel, int32_t mod_num) {
    
    int32_t from_root, to_root, r1 = 0, r2 = 0;
    
    from_root = get_root2_3(rel.from, r1, mod_num);
    
    to_root = get_root2_3(rel.to, r2, mod_num);
    
    //from   --->   root   --->   to
    
    //        r1         mod_num - r2
    
    if (from_root == to_root && rel.rel != ((r1 + mod_num - r2) % mod_num + mod_num) % mod_num) {
        
        return true;
        
    }
    
    //             mod_num - rel.rel
    
    // to -------------------------------> from
    
    // to ---> to_root ---> from_root ---> from
    
    //     r2           r3      mod_num - r1
    
    relation2[to_root].father = from_root;
    
    relation2[to_root].rel = ((- rel.rel + r1 - r2) % mod_num + mod_num) % mod_num;
    
    return false;
    
}



int32_t get_rel2_3(relation rel, int32_t mod_num) {
    
    int32_t from_root, to_root, r1 = 0, r2 = 0;
    
    from_root = get_root2_3(rel.from, r1, mod_num);
    
    to_root = get_root2_3(rel.to, r2, mod_num);
    
    //from   --->   root   --->   to
    
    //        r1         mod_num - r2
    
    if (from_root == to_root) {
        
        return ((r1 + mod_num - r2) % mod_num + mod_num) % mod_num;
        
    }
    
    return -1;
    
}



void init1(int32_t M) {
    
    for (int32_t i = 1; i <= M; i++)
        
        for (int32_t j = 1; j <= M; j++) {
            
            relation1[i][j] = -1;
            
        }
    
}



void init2(int32_t M) {
    
    for (int32_t i = 1; i <= M; i++) {
        
        relation2[i].father = i;
        
        relation2[i].rel = 0;
        
    }
    
}



void print_relation1_array(int32_t M) {
    
    for (int32_t i = 1; i <= M; i++) {
        
        for (int32_t j = 1; j <= M; j++) {
            
            printf("%4d", relation1[i][j]);
            
        }
        
        cout << endl;
        
    }
    
}


/*
int main() {
    
    int32_t n, m, from, to, rel, k;
    
    relation r;
    
    bool flag1 = false, flag2 = false, flag3 = false;
    
    cin >> n >> m;
    
    init1(m);
    
    init2(m);
    
    for (int32_t i = 0; i < n; i++) {
        
        cin >> from >> to >> rel;
        
        r.from = from;
        
        r.to = to;
        
        r. rel = rel;
        
        flag1 = (flag1 || solve1(r, m));
        
        flag2 = (flag2 || solve2_3(r, 2));
        
        //print_relation1_array(m);
        
        //cout << "SOLVE 1 STEP RESULT : " << flag1 << endl;
        
    }
    
    
    
    cout << "SOLVE 1 RESULT : " << flag1 << endl;
    
    cout << "SOLVE 2 RESULT : " << flag2 << endl;
    
    
    
    flag2 = false;
    
    cin >> n >> m >> k;
    
    init2(m);
    
    for (int32_t i = 0; i < n; i++) {
        
        cin >> from >> to >> rel;
        
        r.from = from;
        
        r.to = to;
        
        r.rel = rel;
        
        flag2 = (flag2 || solve2_3(r, 3));
        
    }
    
    
    
    for (int32_t i = 0; i < k; i++) {
        
        cin >> from >> to;
        
        r.from = from;
        
        r.to = to;
        
        cout << "GET RELATION BETWEEN " << from << " AND " << to << " IS " << get_rel2_3(r, 3) << endl;
        
    }
    
    
    
    return 0;
    
}


*/