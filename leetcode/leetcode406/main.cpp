#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static bool cmp(pair<int, int> a1, pair<int, int> b1){
    if(a1.first == b1.first)
        return a1.second <b1.second;
    else
        return a1.first > b1.first;
}
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<pair<int, int>> res;
    for(int i =0; i < people.size(); i++){
        res.insert(res.begin() + people[i].second, people[i]);
    }
    return res;
}
int main() {
    vector<pair<int,int>> p = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    reconstructQueue(p);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}