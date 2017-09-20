#include <iostream>
#include <vector>
using namespace std;
int Partition(vector<int>& data, int start, int end, int pos) {
    int tmp = data[pos];
    swap(data[start], data[pos]);
    while(start < end){
        while (start < end && data[end] >= tmp)
            end--;
        data[start] = data[end];
        while(start < end && data[start] <= tmp)
            start++;
        data[end] = data[start];
    }
    data[start] = tmp;
    return start;
}
int findKthLargest(vector<int>& nums, int k) {
    k = nums.size() - k;
    int i = 0, start = 0, end = nums.size() - 1;
    while(true){
        i = Partition(nums,start,end, start);
        if(i == k)
            return nums[k];
        else if(i > k){
            end = i - 1;
        }
        else
            start = i + 1;
    }
}

int main() {
    vector<int> num = {3,2,1,5,6,4};
    cout << findKthLargest(num,4)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}