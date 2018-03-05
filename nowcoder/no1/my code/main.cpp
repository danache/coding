#include <iostream>

#include <vector>
using namespace std;

int s(vector<int>nums, int i, int j);
int f(vector<int>& nums, int i, int j){
    if(i == j)
        return nums[i];
    return max(nums[i] + s(nums, i+1, j), nums[j] + s(nums,i, j - 1));
}
int s(vector<int>nums, int i, int j){
    if(i == j)
        return 0;
    return min(f(nums, i +1, j), f(nums,i, j -1));
}
int win1(vector<int> nums){
    int sum = 0;
    for(auto n : nums)
        sum += n;
    int a = f(nums, 0, nums.size() - 1);
    return a > (sum - a);
}

int win2(vector<int> nums){
    vector<vector<int>> f(nums.size(), vector<int>(nums.size(), 0));
    vector<vector<int>> s(nums.size(), vector<int>(nums.size(), 0));
    for(int j = 0; j < nums.size(); j++){
        f[j][j] = nums[j];
        for(int i = j - 1; i >= 0; i--){
            f[i][j] =max(nums[i] + s[i + 1][j],nums[j] + s[i][j - 1]);
            s[i][j] = min(f[i + 1][j], f[i][j - 1]);
        }
    }
    return f[0,nums.size() - 1] > s[0,nums.size() - 1] ;
}
int isvalid(string s){
    vector<int> vec(s.size(), 0);
    int res= 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ')'){
            int pre = i - vec[i - 1] - 1;
            if(pre >= 0 && s[pre] == '('){
                vec[i] = vec[i - 1] + 2 + (pre > 0 ? vec[pre - 1]:0);
            }
            res = max(res, vec[i]);
        }

    }
}

int sum1(vector<int>& vec, int k){
    int left = 0, right = 0;
    if(vec.empty())
        return 0;
    int minval = INT32_MAX;
    int tmpsum = 0;
    while(right < vec.size()){
        while(tmpsum < k) {
            tmpsum += vec[right];
        }
        if(tmpsum == k){
            minval = min(minval, right - left+1);
        }
        while(tmpsum > k){
            tmpsum -= vec[left++];
        }
    }
    return minval;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}