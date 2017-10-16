#include <iostream>
#include <vector>
using namespace std;
int characterReplacement(string s, int k) {
    int len =  s.size();
    int maxLength = 0, start = 0, maxCharNum = 0;
    vector<int> vec(26,0);
    for(int end = 0; end < len; end++){
        maxCharNum = max(maxCharNum, ++vec[s[end] - 'A']);
        while(end - start + 1 - maxCharNum > k){
            vec[s[start] - 'A']--;
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
    }
    return maxLength;
}
int main() {
    characterReplacement("AABABBA",1);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}