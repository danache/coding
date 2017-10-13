#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int left = matrix[0][0];
    int right = matrix[m - 1][m - 1];
    int mid = 0;
    while(left <right){
        mid = left + (right - left) /2;
        int num = 0;
        for(int i = 0; i < m; i++){
            int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            num += pos;
        }
        if(num < k){
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}
int main() {
   vector<vector<int>> vec = {{1,5,9},{10,11,13},{12,13,15}};
    cout <<kthSmallest(vec,8);
    return 0;
}