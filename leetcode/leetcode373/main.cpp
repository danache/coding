#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/***
 * class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size())
        {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};
 */
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b) {
        return a.first + a.second > b.first + b.second;
    }
};



vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> res;
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>q;
    for(int i = 0; i < nums1.size()&& i<k; i++){
        q.push(make_pair(i, 0));
    }

    while(k-- && !q.empty()){
        pair<int,int>tmp = q.top();
        res.push_back(make_pair(nums1[tmp.first],nums2[tmp.second]) );
        q.pop();
        if(tmp.second == nums2.size() - 1)
            continue;
        q.push(make_pair(tmp.first, tmp.second + 1));
    }
    return res;
}
int main() {
    vector<int>  nums1 = {1,7,11};
    vector<int> nums2 = {2,4,6};
    kSmallestPairs(nums1, nums2,3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}