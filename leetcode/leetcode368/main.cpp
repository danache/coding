#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    vector<int> res;
    vector<int> parent(nums.size(), 0);
    vector<int> dp(nums.size(), 0);
    int maxnum = 0;
    int index = -1;
    if(nums.empty())
        return res;
    sort(nums.begin(), nums.end());
    for(int i = nums.size() - 1; i >= 0; i--){
        for(int j = i; j < nums.size(); j++){
            if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if(maxnum < dp[i]){
                    maxnum = dp[i];
                    index = i;
                }
            }
        }
    }
    for(int i = 0; i < maxnum; i++){
        res.push_back(nums[index]);
        index = parent[index];
    }
    return res;
}
int main() {
    vector<int> vec = {4,8,10,240};
    largestDivisibleSubset(vec);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}