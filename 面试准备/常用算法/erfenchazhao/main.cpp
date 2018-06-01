#include <iostream>
#include <vector>

using namespace std;


/*
 *
 *
 *
 *
 *
 *
 *
 * 首先确定，是大于还是小于。
 * 如果是大于返回left（因为因为最后left = right + 1)
 * 否则返回right
 * 然后判断等号放在哪里。就看相等时要把这个数字放到哪个区间里。
 */
//退出条件，right + 1 = left
int binary_search(vector<int> vec, int begin, int end, int val){
    int left = begin,right = end;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(vec[mid] == val)
            return mid;
        else if(vec[mid] < val){
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1;
}
/**
 *
//找到最后一个比key小的数，考虑当a[right] == a[left]时，由于退出时 left = right + 1,
//left == mid时，middle == left == right == ,vec[middle] == key如果有的话。
// if a[left] < key,a[right] >= key,left+ 1 = right
//right--;

//查找最后一个小于key的元素
 * @return
 */

int findlastless(vector<int> vec, int begin, int end, int val){
    int left = begin,right = end;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(vec[mid] >= val)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}
/*
 *
 *
 * 找第一个比key大的数字，
 */
int findFirstGreaterEqual(vector<int> vec, int begin, int end, int val){
    int left = begin,right = end;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(vec[mid] <= val){
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    if(left > end)
        return -1;
    else
        return left;
}
int findlastlessEqual(vector<int> vec, int begin, int end, int val){
    int left = begin,right = end;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(vec[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return right;
}

int findFirstGreater(vector<int> vec, int begin, int end, int val){
    int left = begin,right = end;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(vec[mid] > val)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}


int main() {
    vector<int> vec = {1,2,2,2,3,4,5,6,7,7,12,13};
    cout << findFirstGreaterEqual(vec,0,vec.size() - 1, 2)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}