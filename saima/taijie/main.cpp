#include <iostream>
using namespace std;
int main(){
  int n,m;
    cin >> n;
  while(n--){
    cin >> m;
    if(m == 1)
      cout << 0 << endl;

    else if (m == 2)
      cout << 1 << endl;
    else if (m == 3)
      cout << 2 << endl;
    else{
      int a1 = 1;
      int a2 = 2;
      for(int i = 3; i <m; i++){
      	int tmp = a1;
        a1 = a2;
        a2 = a1 + tmp;
      }
      cout << a2 << endl;

    }
  }
  return 0;
}