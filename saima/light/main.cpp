#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n , l, tmp;
    cin >> n >> l;
    vector<int> vec;
    while(n--){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    int num = -1;
    for(int i = 0; i < vec.size() - 1; i++){
        num = max(vec[i+1] - vec[i],num);
    }
    double res =  double(double(num) / 2.0) ;
    double end = double(l - vec[vec.size() - 1]);
    double begin = double(vec[0]);

    res = max(begin,max(end, res));

    printf("%.2f\n", res);
    return 0;
}