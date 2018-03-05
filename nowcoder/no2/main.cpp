#include <iostream>
#include <vector>
#include <stack>


using namespace std;

struct Node{
    int first;
    int second;
    Node(int f, int s){
        first = f;
        second = s;
    }
};
void merge(vector<int>  &vec, int start, int mid, int end ,int &smallsum){
    int i = start, j = mid + 1;
    vector<int> tmp;
    while(i <= mid && j <= end){
        if(vec[i] < vec[j]) {
            smallsum += vec[i] * (end - j + 1);
            tmp.push_back(vec[i++]);
        }
        else
            tmp.push_back(vec[j++]);
    }
    while(i <= mid)
        tmp.push_back(vec[i++]);
    while(j <= end)
        tmp.push_back(vec[j++]);
    for(int i = 0; i < tmp.size(); i++){
        vec[start+ i] = tmp[i];
    }
}
void mergeSort(vector<int>  &vec, int start, int end, int &smallsum){
    if(start == end)
        return;
    int mid = (start + end) >> 1;
    mergeSort(vec, start, mid, smallsum);
    mergeSort(vec, mid + 1,end,  smallsum);
    merge(vec, start, mid, end, smallsum);
}
int solve(vector<int>& vec){
    if(vec.empty())
        return 0;
    vector<int> res(vec.size(), 0);
    int smallnum = 0;
    mergeSort(vec,0,vec.size() - 1,  smallnum);
    return smallnum;
}

int getNextIndex(int length,int i){
    return i == length - 1? 0 : i + 1;
}
long  getcount(int n){
    return  n == 1 ? 0 :n * ( n - 1) / 2;
}
int getNum(vector<int> vec){
    if(vec.empty() || vec.size() == 1)
        return 0;
    int index = -1, maxNum = INT32_MIN;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > maxNum){
            maxNum = vec[i];
            index = i;
        }
    }
    stack<Node*> sta;
    sta.push(new Node(maxNum, 1));
    int j = getNextIndex(vec.size(), index);
    int sum = 0;
    while(j != index){
        int nowval = vec[j];
        while(!sta.empty() && nowval > sta.top() -> first){
            sum += sta.top()->second * 2 + getcount(sta.top()->second);
            sta.pop();
        }
        if(!sta.empty() &&  nowval == sta.top()->first)
            sta.top()->second++;
        else{
            sta.push(new Node(nowval, 1));
        }
        j = getNextIndex(vec.size(), j);
    }
    while(sta.size() != 0){

        Node* tmp = sta.top();
        sta.pop();
        sum += getcount(tmp->second)  ;
        if(sta.size() == 1){
            sum += sta.top()->second > 1 ? tmp->second*2 : tmp->second;
        }
    }
    return sum;
}

int main() {
    vector<int> vec;
    int n;
    cin >> n;
    int tmp;
    while(n--){
        cin >> tmp;
        vec.push_back(tmp);
    }

    cout << getNum(vec);

    return 0;
}