//
//  main.cpp
//  leetcode056
//
//  Created by 萧天牧 on 17/9/5.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

  struct Interval {
      int start;
    int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
    static bool cmp(Interval v1, Interval v2){
        return v1.start < v2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> res;
        if (intervals.empty())
            return res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size() ; i++){
            if(res[res.size() - 1].end >= intervals[i].start){
                res[res.size() - 1].end = max(res[res.size() - 1].end, intervals[i].end);
            }
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution sl = new Solution(
    return 0;
}
