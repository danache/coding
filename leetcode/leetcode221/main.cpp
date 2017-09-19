#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> last(m, 0);
    vector<int> now(m, 0);
    int maxnum = 0;
    for(int i = 0; i < m; i++){
        last[i] = matrix[i][0] - '0';
        maxnum = max(maxnum, last[i]);
    }
    for(int j = 1; j < n;j++){
        now[0] = matrix[0][j] - '0';
        maxnum = max(maxnum, now[0]);
        for(int i = 0; i < m; i++){
            if(matrix[i][j] == '1'){
                now[i] = min(now[i - 1], min(last[i], last[i - 1]))+1;
                maxnum = max(maxnum, now[i]);
            }
            else
                now[i] = 0;
        }
        swap(now, last);
        fill(now.begin(), now.end(), 0);
    }
    return maxnum * maxnum;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}