#include <iostream>
#include <vector>
#include <map>
using namespace std;
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    map<int,int> mp;
    map<int,int>::iterator it;
    for(auto c :C){
        for(auto d:D){
            mp[c+d]++;
        }
    }
    int res = 0;
    for(auto a:A){
        for(auto b:B){
            if(mp.count(-a-b) != 0)
                res += mp[-a-b];
        }
    }
    return res;
}
int main() {
    vector<int> A = { -1, -1};
    vector<int> B = {-1,1};
    vector<int> C = {-1,1};
    vector<int> D = { 1, -1};
    fourSumCount(A,B,C,D);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}