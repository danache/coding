#include <iostream>
using namespace std;

int main() {
    //cout << to_string('0' ^ '0')<<endl;
    string s1,s2;
    cin >> s1 >>s2;
    double num = 0;
    for(int i = 0; i < s1.size() ; i++){
        char c = s1[i];
        char tmp;
        if(('0'<=c && c <= '9') || ('a'<=c && c<='z') || ( 'A' <= c&& c <= 'Z'))
            tmp = '1';
        else
            tmp = '0';

        num +=  1-int((tmp-'0') ^ (s2[i]-'0'));
    }
    printf("%.2f\%\n",(100 * num / s1.size()));
    return 0;
}