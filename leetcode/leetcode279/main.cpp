#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int numSquares(int n) {
    vector<int> vec(n+1,0);
    for(int i = 1; i <=n; i++){
        if(pow(int(sqrt(i)),2) == i )
            vec[i] = 1;
        else{
            int minnum = INT32_MAX;
           for(int j = 1; j* j < i; j++){
               minnum = min(minnum, vec[i -j * j] + 1);
           }

            vec[i] = minNum;
        }
    }
    return vec[n];
}
int main() {
    std::cout << numSquares(12)<<endl;
    return 0;
}