#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    if(amount == 0)
        return 0;
    vector<int> vec(amount + 1, 0);

    for(int i = 1; i <= amount; i++){
        if(find( coins.begin(), coins.end(),i ) != coins.end()){
            vec[i] = 1;
        }
        else{
            int minnum = INT16_MAX;
            for(int j = coins.size() - 1; j >= 0; j--){
                if(coins[j] > i)
                    continue;
                minnum = min(minnum, vec[coins[j]] +  vec[i - coins[j]]);
            }
            vec[i] = minnum;
        }
    }
    return vec[amount] == INT16_MAX ? -1 : vec[amount];
}
int main() {
    vector<int> a = {2};
    cout <<coinChange(a,3);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}