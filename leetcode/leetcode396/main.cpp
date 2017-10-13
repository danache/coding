#include <iostream>
#include <vector>
using namespace std;
int maxRotateFunction(vector<int>& A) {
    int mul = 0;
    int sum = 0;
    for(int i = 0;i < A.size(); i++){
        sum += A[i];
        mul += i * A[i];
    }
    int maxnum = mul;
    for(int i = A.size() - 1; i >= 0; i--){
        mul += sum - A.size()*A[i];
        maxnum = max(maxnum,mul);
    }
    return maxnum;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}