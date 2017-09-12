#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int countheight(vector<int> height){
    stack<int> stk;
    int maxarea = -1;
    for(int i = 0; i < height.size(); i++){

        while(!stk.empty() && height[i] <= height[stk.top()]){
            int j = stk.top();
            stk.pop();
            int k = stk.empty()? -1 : stk.top();
            maxarea = max(maxarea, (i - k - 1) * height[j]);
        }
        stk.push(i);

    }
    while(!stk.empty()){
        int j = stk.top();
        stk.pop();
        int k = stk.empty()? -1 : stk.top();
        maxarea = max(maxarea, int(height.size() - k - 1) * height[j]);
    }
    return maxarea;
}
int count_sub_matrix(vector<vector<int>>num){
    int maxval = -1;
    vector<int> height(num[0].size(),0);
    for(int i = 0; i < num.size(); i++){
        for(int j = 0; j < num[0].size(); j++){
            if (num[i][j] == 0)
                height[j] = 0;
            else
                height[j]++;
        }
        maxval = max(countheight(height), maxval);
    }
    return maxval;
}
int main() {
    vector<vector<int>> a = {{1,0,1,1},{1,1,1,1},{1,1,1,0}};
    cout << count_sub_matrix(a) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}