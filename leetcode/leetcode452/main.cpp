#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}
int findMinArrowShots(vector<pair<int, int>>& points) {
    if(points.empty())
        return 0;
    sort(points.begin(), points.end(), cmp);

    int nowend = points[0].second;
    int arrow = 1;
    for(int i = 1; i < points.size(); i++){
        if(points[i].first <= nowend)
            continue;
        arrow++;
        nowend = points[i].second;
    }

    return nowend;
}
int main() {
    vector<pair<int, int>> a = {{10,16}, {2,8}, {1,6}, {7,12}};
    findMinArrowShots(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}