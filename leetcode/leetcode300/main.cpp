#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    if(nums.empty())
        return 0;
    vector<int> vec(nums.size(),0);
    vec[0] = 1;
    int res = 0;
    for(int i = 1; i < nums.size(); i++){
        int tmpMax = 0;
        for(int j = 0; j < i; j++){
            if(nums[i] > nums[j])
                tmpMax = max(tmpMax, vec[j]);
        }
        vec[i] = tmpMax + 1;
        res = max(res, vec[i]);
    }

    return res;
}
int main() {
    vector<int> tmp = {10,9,2,5,3,7,101,18};
    lengthOfLIS(tmp);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}