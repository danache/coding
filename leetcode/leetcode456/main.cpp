#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool find132pattern(vector<int>& nums) {
    int s3 = INT32_MIN;
    stack<int> sta;
    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] <s3)
            return true;
        else {
            while(!sta.empty() && sta.top() < nums[i]){
                s3 = sta.top();
                sta.pop();
            }
        }
        sta.push(nums[i]);
    }
    return false;
}
using namespace std;
int main() {
    vector<int> a = {-2, 1,2, -2, 1,2};
    vector<int> b = {3, 1, 4, 2};
    vector<int> c = {-1, 3, 2, 0};
    cout <<find132pattern(a)<<endl;
    cout <<find132pattern(b)<<endl;
    cout <<find132pattern(c)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}