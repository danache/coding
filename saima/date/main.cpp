#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int a,b,s;

    cin >> a>>b>>s;
    a = abs(a);
    b = abs(b);
    if(a + b == s)
        cout << "Yes" << endl;
    else if(a + b < s){
        if((s -(a + b)) % 2 == 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}