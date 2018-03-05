#include <iostream>

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
/*****
int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }
string getRes(int n ){
    if(n == 1)
        return "1/1";
    if(n == 2)
        return "2/1";
    int sum = 0;
    for(int i = 2; i < n; i++){
        int tmp = n;
        stack<int> sta;
        while(tmp){
            sum += tmp % i;
            tmp /= i;
        }
    }
    int g = gcd(sum, n-2);
    int a = sum / g, b = (n-2) / g;
    return to_string(a)+"/"+to_string(b);

}
*****/

/*************
int get10(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int get2(int n){
    int sum = 0;

        int tmp = n;
        stack<int> sta;
        while(tmp){
            sum += tmp % 2;
            tmp /= 2;
        }
    return sum;
}

int getRes2(int n){
    int sum = 0;
    for(int i = 1; i <= n;i++){
        if(get10(i) == get2(i))
            sum +=1;
    }
    return sum;
}
 *************************/

int main() {
    int n, m;

    while(cin >> n >>m){
        vector<int> vec;
        for(int i = 0; i < n + m; i++){
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        for(auto b : vec)
            cout << b << " ";
        cout << endl;
    }

    return 0;
}