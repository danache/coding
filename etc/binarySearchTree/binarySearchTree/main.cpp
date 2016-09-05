//
//  main.cpp
//  binarySearchTree
//
//  Created by dan on 16/9/3.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
private:
    string num;
    node* next;
public:
    string getnum(){
        return num;
    }
    void setnum(string _num){
        this->num = _num;
    }
    node* getnext(){
        return next;
    }
    void setnext(node* _next){
        this->next = _next;
    }
};

class hashtable{
    node ** hashTableMain;
    node * hashPool;
    int hashTableLen, hashPoolLen, hashPoolCnt ;
    hashtable(int _hashTableLen, int _hashPoolLen){
        hashTableLen = _hashTableLen;
        hashPoolLen = _hashPoolLen;
        hashPoolCnt = 0;
        this->hashTableMain = new  node*[this->hashTableLen];
        memset(hashTableMain, 0, sizeof(node) * this->hashTableLen);
        hashPool = new  node[hashPoolLen];
    }
    ~hashtable(){
        delete []hashTableMain;
        delete []hashPool;
    }
    int getHashIndex(string str){
        if (this->hashTableLen == 0)
            return -1;
        return getHashnum(str);
    }
    int getHashnum(string str);
    
    node* getNewNode(){
        if (this->hashPoolCnt == this->hashPoolLen)
            return NULL;
        return &(hashPool[hashPoolCnt++]);
    }
    bool search(string str){
        int index = getHashIndex(str);
        if (index == -1)
            return false;
        node* p  = hashTableMain[index];
        while(p != NULL){
            if (p->getnum() == str){
                return true;
            }
            p = p->getnext();
        }
        return false;
    }
    bool insert(string str){
        int index = getHashIndex(str);
        if (index == -1)
            return false;
        if (search(str) == true)
            return true;
        node *p =hashTableMain[index];
        node *q = getNewNode();
        if(q == NULL) return false;
        q->setnum(str);
        q->setnext(p);
        hashTableMain[index]->setnext(q);
        return true;
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
