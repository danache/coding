//
//  main.cpp
//  leetcode435
//
//  Created by 萧天牧 on 17/8/18.
//  Copyright © 2017年 萧天牧. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for an interval.
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool compare(Interval a, Interval b){
        return b.end > a.end;
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1, end = 0;
        if(intervals.size() <= 1)
            return 0;
        end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++){
            if (end <= intervals[i].end){
                end = intervals[i].end;
                count ++;
            }
        }
        return intervals.size() - count;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;

//    s.eraseOverlapIntervals( [1,2], [1,2], [1,2] ])
    std::cout << "Hello, World!\n";
    return 0;
}
