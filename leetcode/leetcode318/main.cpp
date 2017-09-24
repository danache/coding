#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<string>& words) {
    vector<int> vec;
    for(auto w : words){
        int tmp = 0;
        for(int i = 0; i < w.size(); i++){
            tmp |= 1 << (w[i] - 'a');
        }
        vec.push_back(tmp);
    }
    int maxp = 0;
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words.size(); j++){
            if((vec[i] & vec[j]) == 0 && (words[i].size() * words[j].size() > maxp)){
                maxp = words[i].size() * words[j].size();
            }
        }
    }
    return maxp;
}
int main() {
    vector<string> a = {"abcw","baz","foo","bar","xtfn","abcdef"};
    maxProduct(a);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}