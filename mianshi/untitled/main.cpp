 #include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//
 int findLastLessEqual(vector<int> arr, int l,int r, int key) {
      int left = min(l,0);
      int right = r - 1;
      int mid;

      while (left <= right) {
          mid = (left + right) / 2;
          if (key < arr[mid]) {
              right = mid - 1;
          } else {
              left = mid + 1;
          }
      }
      return right;
  }

//int main() {
//    int N,K,H;
//    int tmp;
//    vector<int> vec;
//    cin >> N >> K >> H;
//    for(int i = 0; i < N ; i++){
//        cin >> tmp;
//        vec.push_back(tmp);
//    }
//    sort(vec.begin(),vec.end());
//    K = min(K,N);
//    if(vec[0] > H)
//        cout << 0 << endl;
//    else {
//        int nowHeight = 0;
//        int nowpos = -1;
//
//        while (K--) {
//            int pos = findLastLessEqual(vec,nowpos,vec.size(),nowHeight + H);
//            if(pos == vec.size() || nowpos == pos)
//                break;
//            else {
//                nowHeight = 2 * vec[pos] - nowHeight;
//                nowpos = findLastLessEqual(vec, pos, vec.size(), nowHeight);
//                if(nowpos == vec.size() - 1)
//                    break;
//            }
//        }
//        cout << nowHeight << endl;
//
//        return 0;
//    }
//
//}
// int findFirstGreater(vector<int> arr, int l,int r, int key)
//  {
//      int left = l;
//      int right = r;
//      int mid;
//
//      while (left <= right) {
//          mid = (left + right) / 2;
//          if (key < arr[mid]) {
//              right = mid - 1;
//          }
//          else {
//              left = mid + 1;
//          }
//      }
//      return left;
//  }
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main() {
//    int m , n,tmp;
//    cin >> m >> n;
//    map<int,int> mp1;
//    map<int,int> mp2;
//    vector<int> vec1;
//    vector<int> vec2;
//    double sum1 = 0.0;
//    double sum2 = 0.0;
//
//    for (int i = 0; i < n; i++){
//    cin >> tmp;
//    mp1[tmp]++;
//    vec1.push_back(tmp);
//    sum1 += tmp;
//    }
//    for (int i = 0; i < m; i++){
//    cin >> tmp;
//    mp2[tmp]++;
//    vec2.push_back(tmp);
//    sum2 += tmp;
//    }
//    double avg1 = sum1 / n;
//    double avg2 = sum2 / m;
//    int times = 0;
//    if(avg1  == avg2)
//        cout << 0 << endl;
//    else if(avg1 < avg2){
//        int beginpos = 0;
//
//        while(true) {
//            if(m == 1)
//                break;
//            vector<int>::iterator it  = upper_bound(vec2.begin()+beginpos, vec2.end(), avg1);
//
//            if (it == vec2.end() || *it ==) {
//                cout << times << endl;
//                break;
//            }
//            else{
//                beginpos = it - vec2.begin();
//                times++;
//                sum2 -= *it;
//                m--;
//                if(mp1.count(*it) == 0){
//                    n++;
//                    sum1++;
//                }
//                avg1 = sum1 / n;
//                avg2 = sum2 / m;
//            }
//        }
//    }
//    else{
//        int beginpos = 0;
//        while(true) {
//            if(n == 1)
//                break;
//            vector<int>::iterator it  = upper_bound(vec1.begin()+beginpos, vec1.end(), avg1 - avg2);
//            if (it == vec2.end()) {
//                cout << times << endl;
//                break;
//            }
//            else{
//                beginpos = it - vec1.begin();
//                times++;
//                sum1 -= *it;
//                n--;
//                if(mp2.count(*it) == 0){
//                    mp2[*it] = 1;
//                    m++;
//                    sum2+=*it;
//                }
//                avg1 = sum1 / n;
//                avg2 = sum2 / m;
//            }
//        }
//    }
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
 using namespace std;
 int dp[111111];
 int main() {
     memset(dp, 0, sizeof(dp));
     vector<int> v;
     dp[0] = 1;
     int n, k, h;
     cin >> n >> k >> h;
     int ma = -111;
     int x;
     for (int i = 0; i < n; i++) {
         scanf("%d", &x);
         v.push_back(x);
         ma = max(ma, x);
     }
     ma = ma + 111;
     sort(v.begin(), v.end());
     for (int i = 0; i < ma; i++) {
         int u = i - h;
         vector<int>::iterator index1 = lower_bound(v.begin(), v.end(), u);
         if (index1 == v.end()) {
             continue;
         }
         for (vector<int>::iterator j = index1; *j < i && j != v.end(); j++) {
             int t = i - *j;
             if (*j - t >= 0)
                 dp[i] = max(dp[i], dp[*j - t]);
         }
     }
     int ans;
     for (int i = 111111; i >= 0; i--) {
         if (dp[i] == 1) {
             ans = i;
             break;
         }
     }
     cout << ans << endl;
     return 0;
 }