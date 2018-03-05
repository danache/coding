#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    long x, f, d, p;
    cin >> x >> f >> d >> p;
    long left = 0, right = d / x + 2;
    long res =  - 1;
    while(left <= right){
        long mid = left + (( right - left) >> 1);
        long cost = mid * x + p * max(mid - f, long(0));
        if(cost < d)
            left = mid + 1;
        else if(cost == d) {
            res = mid;
            break;
        }
        else
            right = mid - 1;
    }
    res = res == -1 ? left- 1 : res;
    cout << res << endl;
    return 0;
}

/* p 5
int main(){
    vector<int> vec;
    int n;
    cin >> n;
    int ymp;
    for(int i = 0; i < n; i++){
        cin >> ymp;
        vec.push_back(ymp);
    }
    vector<int> b;
    vector<int> c;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            b.push_back(vec[i]);
        else
            c.push_back(vec[i]);
    }
    if(n % 2 == 1){
        for(int i = b.size() - 1; i >= 0; i--){
            cout << b[i] << " ";
        }
        for(int i = 0; i < c.size() - 1; i++)
            cout << c[i] << " ";
        cout << c[c.size() - 1] <<endl;
    }
    else{
        for(int i = c.size() - 1; i >= 0; i--){
            cout << c[i] << " ";
        }
        for(int i = 0; i < b.size() - 1; i++)
            cout << b[i] << " ";
        cout << b[b.size() - 1] <<endl;
    }


}
*/

/*
int main(){
    string s;
    cin >> s;
    int maxNum = 1;
    int pre = 1;
    for(int i = 1; i < s.size(); i++){
        if((s[i] - '0') ^ (s[i - 1] -'0')){
            pre += 1;
            maxNum = max(maxNum, pre);
        }
        else
            pre = 1;
    }

    cout << maxNum<<endl;
    return 0;

}
 */
/*********
 * problem1
 * @return

int main() {
    string s;
    cin >> s;
    map<char,int> mp;
    if(s.size() == 0)
        cout << 0 << endl;
    else {
        for(auto c : s)
            mp[c]++;
        if(mp.size() > 1)
            cout << 2;
        else
            cout << 1;
    }
}
 */
/*
 * problem 2
int main(){
    int n;
    cin >> n;
    vector<int> vec;
    while(n--){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    if(vec.empty() || vec.size() == 1 || vec.size() == 2)
        cout << "Possible"<<endl;
    else{
        int cha = vec[1] - vec[0];
        bool flag = true;
        for(int i = 2; i < vec.size(); i++)
            if(vec[i] - vec[i - 1] != cha) {
                flag = false;
                break;
            }
        if(flag)
            cout << "Possible"<<endl;
        else
            cout << "Imossible"<<endl;
    }
    return 0;
}
 */
