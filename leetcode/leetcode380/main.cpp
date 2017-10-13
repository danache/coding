#include <iostream>
#include <vector>
#include <map>
using namespace std;

class RandomizedSet {
private:
    map<int,int> mp;
    int count;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val) == 1)
            return false;
        else{
            mp[val]++;
            this->count++;
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val) == 0)
            return false;
        else {
            map<int,int>::iterator it = mp.find(val);
            mp.erase(it);
            this->count--;
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        if(this -> count == 0)
            return -1;
        int index = rand() % this->count;
        map<int,int>::iterator it = mp.begin();
        for(int i = 0;i < index; i++)
            it++;
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
int main() {
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(1);
    bool param_2 = obj->remove(2);
    bool param_3 = obj->insert(2);
    int n1 = obj->getRandom();
    bool param_4 = obj->remove(1);
    bool param_5 = obj->insert(2);
    int n2 = obj->getRandom();



    std::cout << "Hello, World!" << std::endl;
    return 0;
}