#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int i = m - 1, j = 0;
    while(0<=i && i < m && 0<=j && j < n){
        int tmp = matrix[i][j];
        if(target == matrix[i][j])
            return true;
        else if(target < matrix[i][j])
            i--;
        else
            j++;
    }
    return false;
}
int main() {
    vector<vector<int>> a={
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
    };
    searchMatrix(a,5);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}