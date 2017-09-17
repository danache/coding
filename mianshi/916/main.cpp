#include <iostream>
#include <vector>
using namespace std;
int getdiff(vector<string> map, int i, int j){
    string s1 = map[i];
    string s2 = map[j];
    int diff = 0;
    for(int i = 0; i < s1.size(); i++)
        diff += (s1[i] -'0') ^ (s2[i] - '0');
    return diff;

}

int main() {
    vector<string> map = {
            "1111110","0110000","1101101",
            "1111001","0110011","1011011",
            "1011111","1110000","1111111",
            "1111011"
    };
    vector<vector<int>> vec(map.size(), vector<int>(map.size(), 0));
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map.size(); j++){
            vec[i][j] = getdiff(map,i,j);
        }
    }
    cout << 1;
}