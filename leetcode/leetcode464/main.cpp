#include <iostream>
#include <vector>
using namespace std;
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    vector<bool> vec(desiredTotal + 1,false);
    for(int i = 1; i < desiredTotal + 1; i++){
        if(i <= desiredTotal){
            vec[i] = true;
        }
        else{

        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}