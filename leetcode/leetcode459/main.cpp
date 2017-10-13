#include <iostream>
using namespace std;
bool repeatedSubstringPattern(string s) {
    bool flag = false;
    int jiange = 1;
    while(jiange <= s.size() / 2 ){
        if(s.size() % jiange != 0){
            jiange++;
            continue;
        }
        flag = true;
        for(int i = 0; i<  jiange; i++){
            char c = s[i];
            int j = i + jiange;
            while(j < s.size()){
                if(s[j] != c) {
                    flag = false;
                    break;

                }
                j += jiange;
            }
            if(!flag)
                break;
        }

        if(flag)
            return true;
        jiange++;
    }
    return false;
}
int main() {
    repeatedSubstringPattern("babbbbaabb");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}