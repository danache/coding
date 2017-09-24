#include <iostream>
using namespace std;
int integerBreak(int n) {
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    int prod = 1;
    while(n > 4){
        prod *= 3;
        n -= 4;
    }
    prod *= n;
    return prod;


}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}