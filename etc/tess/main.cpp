#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int*b){
    int *c;
    *c=*a;*a=*b;*b=*c;
};
void swap_l(int &a, int &b){
    int c;
    c=a;a=b;b=c;
};
void swap2(int *a, int i, int j){
    int d=a[i];
    a[i]=a[j];
    a[j]=d;
};
void bubble(int *a , int b){
    for(int j=0;j<b;j++){
        for(int i=0;i<b;i++){
            if(a[i]>a[i+1])
                swap2(a,i,(i+1));
        };
    };
}

int main() {
    int a[] = {1,3,54,76,78,3,42,13,42,76,45};
    int b = sizeof(a)/sizeof(*a);
    bubble(a,11);
//    swap2(a,3,5);
    for(int i = 0; i < b; i++)
        cout << a[i]<<" ";
    cout << endl;
}
