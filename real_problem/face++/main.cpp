#include <iostream>
using namespace std;
int main() {
    int rf = 1;
    int fsize = 3;
    for(int i = 0; i < 5; i++){
        rf = ((rf-1)*2)+3;
    }
    cout <<rf<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}