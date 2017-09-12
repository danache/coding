#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<int> getmaxwindow(vector<int> vec, int windowSize){
    deque<int> dq;
    vector<int> res;
    for(int i = 0; i  < vec.size(); i++){
        if(dq.empty()){
            dq.push_back(i);
        }
        else{

            while (!dq.empty() &&vec[dq.back()] < vec[i] ){
                dq.pop_back();
            }
            dq.push_back(i);

        }
        if(dq.front() == i - windowSize)
            dq.pop_front();
        if(i - windowSize + 1 >= 0)
            res.push_back(vec[dq.front()]);
    }
    return res;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int>  a = {4,3,5,4,3,3,6,7};
    vector<int> res = getmaxwindow(a, 3);
    for(auto n : res)
        cout << n <<" ";
    cout << endl;

    return 0;
}