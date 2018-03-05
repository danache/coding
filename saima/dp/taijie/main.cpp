#include<iostream>
#include<vector>
using namespace std;
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1,maxleft = height[left], maxright = height[right];
    if(height.empty() || height.size() < 3)
        return 0;
    left++;
    right--;
    int val = 0;
    while(left <= right){
        if(height[left] >= maxleft){
            maxleft = height[left++];
            continue;
        }
        if(height[right] >= maxright){
            maxright = height[right--];
            continue;
        }
        if(maxleft < maxright){
            val += maxleft-height[left++];
            continue;
        }
        else{
            val += maxright - height[right--];
        }
    }
    return val;
}
int main(){
int n;
 vector<int> vec = {3,1,2,5,4,6};
    cout << maxArea(vec)<<endl;
  return 0;
}