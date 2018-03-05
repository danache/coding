#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    ListNode* next;
    int val;
    ListNode(){};
};

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
ListNode* partition(ListNode* pbegin, ListNode* pend){
    if(pbegin == pend || pbegin -> next == pend)
        return pbegin;
    int key = pbegin -> val;
    ListNode *p=pbegin, *q = pbegin;
    while(q != pend){
        if(q -> val < key){
            p = p -> next;
            swap(&p -> val, &q -> val);
        }
         q = q -> next;
    }
    swap(&p -> val, &pbegin -> val)
    return p;
}
void quicksort(ListNode *pBegin,ListNode *pEnd){
    if(pBegin==pEnd||pBegin->next==pEnd)
        return;
    ListNode *mid=partition(pBegin,pEnd);
    quicksort(pBegin, mid);
    quicksort(mid -> next, pEnd);

}
struct HeapSort{
    vector<int> vec;
    HeapSort(){
        vec = {};
    }
    HeapSort(vector<int> v){
        vec = v;
    }

    void update(int end){
        for(int j = end - 1; j > 0; j--){
            int parent = j >> 1;
            int child = j;
            if(j < end - 1 && vec[j] < vec[j + 1])
                child++;
            if(vec[child] > vec[parent]){
                swap(vec[child] ,vec[parent]);
            }
        }

    }
    vector<int> makeHeap(){
       for(int j = vec.size() ; j > 0; j--){
           update(j);
           swap(vec[0],vec[j - 1]);

       }
        return vec;
    }
};

struct quickSort{
    vector<int> vec;
    quickSort(){
        vec = {};
    }
    quickSort(vector<int> v){
        vec = v;
    }
    void quick(int left, int right){
        int i = left, j = right;
        int cmp = vec[(left + right) >> 1];
        while(i <= j){
            while(vec[j] > cmp)
                j--;
            while(vec[i] < cmp)
                i++;
            if(i <= j){
                swap(vec[i],vec[j]);
                i++;
                j--;
            }
        }
        if(left < j)
            quick(left, j);
        if(i < right)
            quick(i, right);

    }
    int sort(int left, int right){
        int bijiao = vec[left];
        int i = left + 1;
        int j = right;
        while(i < j){
            while( i < j && i < bijiao)
                i++;


            while(j > bijiao)
                j--;
            if(i)
        }
    }
    void quick2(int left, int right){

    }

};
int main() {
//    vector<int> v = {3,4,5,1,6,6,7,9,1,0,2};
//   quickSort a(v);
//    a.quick(0,v.size() -1);
//v = a.vec;
//    for(auto n : v)
//        cout << n << " ";
//    cout << endl;
    int n ;
    cin >> n;
    cout << (n &(n-1) == 0)<<endl;
    return 0;
}