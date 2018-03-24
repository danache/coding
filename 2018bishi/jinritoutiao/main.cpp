#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;



/////////////////////////////problem 1 /////////////////////////
/*
 * 在N个元素的数组中，找到差值为k的数字对去重后的个数
 * 比较简单，答案用的双指针
 */
/////////////////////////////problem 2 /////////////////////////
/*
 * 定义两个字符s,m定义两种操作.
 * 1:m = s; s = s + s;
 *
 * 2: s = s + m。
 * 初始化s长度为1,求拼接到n的最小步数。
 *
 *
 * 分析：对于笔试中的此类题，可以直接尝试用搜索。这里为宽度搜索
 */
int problem2(int N){
    queue<pair<int,int>> que;
    map<pair<int,int>,int> mp;
    que.push(make_pair(1,1));
    mp[make_pair(1,1)] = 0;
    while(!que.empty()){
        pair<int,int> tmp = que.front();

        que.pop();
        if(tmp.first == N){
            cout << mp[tmp] << endl;
            break;
        }

        pair<int,int> t = tmp;
        t.second = t.first;
        t.first *= 2;
        if(mp.count(t) == 0){
            que.push(t);
            mp[t] = mp[tmp]+1;
        }

        t = tmp;
        t.first += t.second;
        if(mp.count(t) == 0){
            que.push(t);
            mp[t] = mp[tmp]+1;
        }
    }
}
/////////////////////////////problem 3 /////////////////////////
/*模拟题，没啥可参考的，可以复习一下利用栈计算表达式
 */
/////////////////////////////problem 4 /////////////////////////
/*给定一个包含n个证书元素的集合a，一个包含m个整数元素的集合b。定义magic操作为
 * 从一个集合里取出一个元素放到另一个集合里，使得如此操作后两个集合的平均值都大于从前。
 * a.不能把集合取空了
 * b.值为x的元素从a放入b，如果b中已经有了x，那么b的均值不变（因为元素不可以重复），但是a的要改变（因为被取出了）
 *
 * 思路：
 * 分析之后得到，先统计两个数组，操作应该从均值较大的数组取出放入另一边，去除元素每次从bi另外一个数组的均值大的开始。
 * 思路明确，但是变成能力不够导致写不出来，应该要多家练习。
 */

bool cmp(double n, double m){
    if (n-m < 0.000000000000000000000000000000001)
        return 0;
    return n - m > 0 ?1:-1;
}
inline long double avg(long long k, int m)
{
    return (long double)k/m;
}

int problem4(){
    int n,m,tmp;
    set<int> st1;
    set<int> st2;

    double sum1 = 0;
    double sum2 = 0;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        sum1 += tmp;
        st1.insert(tmp);
    }

    for(int i = 0; i < m; i++){
        cin >> tmp;
        sum2 += tmp;
        st2.insert(tmp);
    }

    double avg1 = avg(sum1, n);
    double avg2 = avg(sum2, m);
    if(cmp(avg1,avg2) == -1){
        swap(n,m);
        swap(st1,st2);
        swap(sum1,sum2);
        swap(avg1,avg2);
    }
    int ans = 0;
    for(auto k : st1){
        if(cmp(k,avg(sum1,n)) >= 0)
            break;
        if(!st2.count(k) && cmp(k,avg(sum2,m)) > 0){  //如果b中没有k,且k比b的均值大，那么k加入b

            ans++;
            sum2 += k;
            sum1 -=k;
            n--;
            m++;
            st2.insert(k);

        }
    }

}


/////////////////////////////problem 4 /////////////////////////
/*终于到了绞尽脑汁也没做出来的problem5了，结果还是搜索。。这告诉我们，不会做先暴力。。
 * 已知空中有N个高度互不相同的跳板，在0的地方开始，每次选取高度值差小于等于h的跳板，然后跳到镜像位置，问跳k次最多多高？
 * 一开始用的贪心，错误。答案用的光搜：
 *
 */
int problem5(){
    int N, K, H,tmp;
    map<int,int> mp;
    cin >> N >> K >> H;
    vector<int> vec (100000,0);
    vector<bool> visit (100000,0);

    for(int i = 0; i < N; i++){
        cin >> tmp;
        vec[tmp] = 1;
    }
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    int ans = 0;
    while(!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        if(p.second > K)
            break;
        ans = max(ans,p.first);
        for(int i = 1; i <= H ;i ++){
            if(vec[p.first + i] && !visit[p.first + 2 * i]){
                visit[p.first + 2 * i] = 1;
                que.push(make_pair(p.first + 2 * i,p.second + 1));
            }
            if(p.first - 2 * i >= 0 && vec[p.first - i] && !visit[p.first - 2 * i]){
                visit[p.first - 2 * i] = 1;
                que.push(make_pair(p.first - 2 * i,p.second + 1));
            }

        }
    }
    cout << ans << endl;
}


int main() {
    //problem2(6);
    problem5();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}