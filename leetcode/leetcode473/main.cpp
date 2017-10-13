#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(vector<int> num, vector<int>& sum, int index , int target){
  if(index == num.size()){
      if(sum[0] == target && sum[1] == target && sum[2] == target && sum[3] == target)
          return true;
      else
          return false;
  }
    for(int i = 0; i < 4; i++){
        if(target > sum[i] + num[index] )
            continue;
        sum[i] += num[index];
        if(dfs(num,sum,index+1,target))
            return true;
        sum[i] -= num[index];
    }
    return false;
}
bool makesquare(vector<int>& nums) {
    int sum = 0;
    for(auto n : nums)
        sum += n;
    if(nums.empty() || sum % 4 != 0)
        return false;
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    vector<int>a (4,0);
    return dfs(nums,a,0,sum / 4);
}
int main() {
    vector<int> a = {1,1,2,2,2};
    makesquare(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}