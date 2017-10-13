#include <iostream>
#include <vector>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if(s.empty() || p.empty())
        return res;

    vector<int> hash(256,0);
    for(auto c : p)
        hash[c]++;
    int left  = 0 , right = 0, count = p.size();
    while(right < s.size()) {
        if (hash[s[right]] >= 1) {
            count--;
        }
        hash[s[right]]--;
        right++;
        if (count == 0)
            res.push_back(left);
        if (right - left == p.size()) {
            if (hash[s[left]] >= 0)
                count++;
            hash[s[left]]++;
            left++;
        }
    }
        return res;

}
int main() {
    string s1 = "cbaebabacd" ;
    string p =  "abc";
    findAnagrams(s1,p);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}