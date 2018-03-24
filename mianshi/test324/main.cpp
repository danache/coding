#include <iostream>
using namespace std;
#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;

int findLastLessEqual(vector<int> arr, int l,int r, int key) {
    int left = 0;
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
int main() {
    vector<int> a = {1,3,5,7,9};
    cout << findLastLessEqual(a,0,5,10)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}