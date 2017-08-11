//
//  main.cpp
//  leetcode207
//
//  Created by 萧天牧 on 17/7/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
//bool dfs(vector<vector <int> > graph,  vector<vector <int> >& flag, int x, int y, int num){
//    if(flag[x][y] == num)
//        return false;
//    bool tag = true;
//    flag[x][y] = num;
//    for(int i = 0; i < flag.size(); i++){
//        bool flag1 =(graph[y][i] == 1);
//        if(graph[y][i] == 1){
//            if(flag[y][i] == num)
//                return false;
//            tag &= dfs(graph, flag, y, i, num);
//        }
//    }
//    return tag;
//}
//bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//    vector<vector <int> > graph(numCourses ,vector<int>(numCourses,0));
//    vector<vector <int> > flag(numCourses ,vector<int>(numCourses,0));
//    for(int i = 0; i < prerequisites.size(); i++){
//        graph[prerequisites[i].first][prerequisites[i].second] = 1;
//    }
//    int pos = 1;
//    for(int i = 0; i < graph.size(); i++){
//        for(int j = 0; j < graph[0].size(); j++){
//            if(graph[i][j] == 1 && flag[i][j] == 0){
//                if(!dfs(graph, flag, i, j,pos++))
//                    return false;
//            }
//            
//        }
//    }
//    return true;
//    
//}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
    if(numCourses == 0) return false;
    vector<int> indegree(numCourses, 0);
    map<int, multiset<int>> hash;
    
    for(auto val: prerequisites){
        indegree[val.first]++;
        hash[val.second].insert(val.first);
    }
    
    for(int i = 0, j; i < numCourses; i++){
        for(j = 0; j < numCourses; j++)
            if(indegree[j]==0)
                break;
        if(j == numCourses)
            return false;
        indegree[j]--;
        for(auto val: hash[j]) indegree[val]--;
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    pair<int, int> t = make_pair(1, 0);
    pair<int, int> s = make_pair(2, 1);
    
    vector<pair<int, int>> a = {t,s};
    cout << canFinish(3, a);
    std::cout << "Hello, World!\n";
    return 0;
}
