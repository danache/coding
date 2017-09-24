#include <iostream>
#include <vector>
#include <stack>
using namespace std;
bool increasingTriplet(vector<int>& nums) {
    int a = INT32_MAX,b=INT32_MAX;
    for(int i = 0; i<nums.size() ;i++){
       if(nums[i] <= a){
           a= nums[i];
       }
        else if (nums[i] <= b){
           b = nums[i];
       }
        else
           return true;
    }
    return false;
}
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    cout << increasingTriplet(a)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}