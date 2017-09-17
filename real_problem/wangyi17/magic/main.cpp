#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int a = -1?1:0;
    cout << a;
    cin >> n;
    vector<int> vec;
    int tmp;
    vector<int> count ;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }


    return 0;
}
//Q5
/*
int main() {
    int t ;
    cin >> t;
    int n;


    while(t--) {
        scanf("%d", &n);
                int cnt4 = 0;
                int cnt2 = 0;
                int cnt1 = 0;
                for(int i = 0; i < n; i++) {
                        int x;
                        scanf("%d", &x);
                        if(x % 4 == 0) cnt4++;
                        else if(x % 2 == 0) cnt2++;
                        else cnt1++;
                    }
                if(cnt2 == 0) {
                        if(cnt4 >= cnt1 - 1)
                            printf("Yes\n");
                        else
                            printf("No\n");
                    } else {
                        if(cnt4 >= cnt1)
                            printf("Yes\n");
                        else
                            printf("No\n");
                    }
            }
    return 0;
}

*/
//q4
/*
int main() {
    int n, l;
    cin >>n >> l;
    vector<vector<int>> vec(n, vector<int>(0, 0));
    int tmp = 0;
    for(int i = 0; i < n - 1; i++){
        cin >> tmp;
        vec[tmp].push_back(i + 1);
    }
    int num = 1;
    queue<int> que;
    que.push(0);
    que.push(-1);
    while(!que.empty()){
        int top = que.front();
        que.pop();
        if (top == -1){

            if(!que.empty()) {
                que.push(-1);
                num++;
            }
        }else{
            for(auto n : vec[top]){
                que.push(n);
            }
        }
    }
    int d = min(l, num);
    cout << min((n), 1 + d + (l - d) / 2) << endl;
    return 0;
}
 */
/******************
 * this is q1
 * @return

int main() {
    int n;
    cin >> n;
    stack<string> sta;
    while(n){
        if(n % 2 == 0) {
            sta.push("2");
            n = n / 2 - 1;
        }
        else{
            sta.push("1");
            n = (n - 1) / 2;
        }
    }
    string res = "";
    while (!sta.empty()) {
        res += sta.top();
        sta.pop();
    }
    std::cout << res << std::endl;
    return 0;
}*/

///////////q2
/*
int main() {
    int n;
    cin >>n;
    int tmp = n;
    int res= 0;
    while(tmp){
        res *= 10;
        res += tmp % 10;
        tmp /= 10;
    }

    res += n;
    cout << res;
    return 0;
}
*/

/**
 *
 * @return
Q3
int main() {
    string s ;
    int head = 0;
    vector<string> st;
    for(int i = 0; i < s.size(); i++){
        if(i + 1< s.size() && s[i] != s[i + 1]){
            st.push_back(s.substr(head, i - head + 1));
            head = i + 1;
        }
    }
    if(head < s.size())
        st.push_back(s.substr(head, s.size() - head));

    int nowstr = 0;
    int alllen = 0;
    for(auto c : st){
        nowstr += 1;
        alllen += c.size();
    }
    float res = float(alllen *1.0/  nowstr);
    printf("%.2f", res);
    return 0;
}
  */