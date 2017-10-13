#include <iostream>
#include <vector>
using namespace std;
bool PredictTheWinner(vector<int>& nums) {
    vector<vector<int>> f(nums.size(), vector<int>(nums.size(), 0));
    vector<vector<int>> s(nums.size(), vector<int>(nums.size(), 0));
    for(int j = 0; j < nums.size(); j++){
        f[j][j] = nums[j];
        for(int i = j - 1; i>= 0; i--){
            f[i][j] = max(nums[i] + s[i + 1][j], nums[j] + s[i][j - 1]);
            s[i][j] = min(f[i + 1][j], f[i][j - 1]);
        }
    }
    return f[0][nums.size() - 1] > s[0][nums.size() - 1];
}

int main() {
    vector<int> a = {1, 5, 2};
    std::cout << PredictTheWinner(a) << std::endl;
    return 0;
}