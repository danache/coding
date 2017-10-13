#include <iostream>
#include <vector>
using namespace std;
bool isSubsequence(char* s, char* t) {
    while (*t)
        s += *s == *t++;
    return !*s;
}
int main() {
    isSubsequence("b","c");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}