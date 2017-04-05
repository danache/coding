#include <iostream>
#include <stdlib.h>
using namespace std;

long **basic;
long **c;

long **mul(long **pInt, long **rec);

long **rec(long long x) {
    if (x > 1) {
        long long m = x / 2;
        long long n = x - m;
        return mul(rec(m), rec(n));
    } else {
        return basic;
    }
}

long **mul(long **a, long **b) {
    for(int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j])%1000000007L;
        }
    }
    return c;
}


int main() {
    basic = new long*[2];
    for (int i = 0; i < 2; ++i) {
        basic[i] = new long[2];
    }
    basic[0][0] = 2;
    basic[0][1] = 3;
    basic[1][0] = 1;
    basic[1][1] = 0;
    c = new long*[2];
    for (int i = 0; i < 2; ++i) {
        c[i] = new long[2];
    }
    long long n;
    cin >> n;
    if (n == 1 || n == 0) {
        cout << n;
        delete basic;
        delete c;
        return 0;
    }
    long long x = n - 1;
    long **a = rec(x);
    cout << a[0][0] << endl;
    cout << a[0][1] << endl;
    cout << a[1][0] << endl;
    cout << a[1][1] << endl;
    delete basic;
    delete c;
    return 0;
}
