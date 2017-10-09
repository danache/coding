#include <iostream>
#include <vector>
using namespace std;
int helper(string s, int k, int first, int last){
    vector<int> a(26,0);
    for(int i = first; i <= last; i++)
        a[s[i] - 'a']++;
    int maxlem = 0 ;
    for(int i = first; i <= last; i++){
        while(i <= last && a[s[i] -'a'] < k)
            i++;
        if(i == last + 1)
            break;
        int j = i + 1;
        while(j <= last && a[s[j] - 'a'] >= k)
            j++;
        if(j == last +1&& i == first)
            return j - i;
        maxlem = max(maxlem,helper(s,k,i,j - 1));
        i = j;
    }
    return  maxlem;
}
int longestSubstring(string s, int k) {
    return helper(s,k,0,s.size() - 1);
}
int main() {
    cout <<longestSubstring("aacbbbdc",2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}