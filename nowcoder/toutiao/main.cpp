#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
///////////////////////////////
//Problem 1
///////////////////////////////
/*
 *

int problem1(vector<int> vec){
    sort(vec.begin(), vec.end());
    vector<int> count;
    int nowvalid = 1;
    int tail = vec[0] + 10;
    for(int i = 1; i < vec.size(); i++){
        if(vec[i] <= tail){
            nowvalid ++;
        }
        else{
            count.push_back(nowvalid);
            nowvalid = 1;
        }
        tail = vec[i] + 10;
    }
    count.push_back(nowvalid);
    int sum = 0;
    for(auto c : count){
        if(c == 3 )
            continue;
        sum += 3 - c % 3;
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    int tmp;
    vector<int> vec;
    while(n--){
        cin >> tmp;
        vec.push_back(tmp);
    }
    problem1(vec);
    std::cout << problem1(vec) << std::endl;
    return 0;
}
 */


///////////////////////////////
//Problem 2
///////////////////////////////
//int main(){
//    return 0;
//}


/***
problem3
***/



long long getSum(long long start,long long n){
    long long end = start + 1;
    long long sum = 0;
    while(start <= n){
        sum += max(long(0),(min(long(n+1),end)-long(start)));
        start *=10;
        end *= 10;
    }
    return sum ;
}
int findKthNumber(int n, int k) {

    int res = 1;
    --k;
    while(k > 0){
        long sum = getSum(res, n);
        if(sum <= k){
            k -=sum;
            ++res;
        }else{
            res *= 10;
            --k;
        }
    }
    return res;

}

int main(){
    int n, k;
    cin >> n >> k;
    cout << findKthNumber(n,k)<<endl;
    return 0;

}