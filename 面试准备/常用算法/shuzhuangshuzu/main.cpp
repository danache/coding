#include <iostream>
using namespace std;
#define N 100000+10

int a[N];
int lowbit(int n){
    return n & (-n);
}

void add(int x, int addnum){
    while(x <= N){
        a[N] += addnum;
        x += lowbit(x);
    }
}

int query(int x){
    int num = 0;
    while(x > 0){
        num += a[x];
        x -= lowbit(x);
    }
    return num;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}