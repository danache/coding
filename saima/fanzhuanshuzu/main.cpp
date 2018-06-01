#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> vec){
    int left = -1;
    int right = -1;
    for(int i = 0; i < vec.size(); i++){
        if(i < vec.size() - 1 && vec[i] > vec[i + 1] && left == -1)
            left = vec[i];
        if(left != -1 && i < vec.size() - 1 && vec[i] < vec[i+1]) {
            right = vec[i + 1];
            break;
        }

    }
    if ( right > left)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
int main() {
    int n,tmp;
    vector<int> vec ;
    cin >> n;
    while(n--){
        cin >> tmp;
        vec.push_back(tmp);
    }

    solve(vec);

    return 0;
}