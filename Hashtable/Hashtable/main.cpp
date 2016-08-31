//
//  main.cpp
//  Hashtable
//
//  Created by dan on 16/8/22.
//  Copyright © 2016年 dan. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>

class hashnode{
private:
    string data;
    hashnode* next;
public:

    string getdate(){
        return this->data;
    }
    
    hashnode* getnext(){
        return this->next;
    }
    
    void setdata(string _data){
        this->data = _data;
    }
    
    void setnext(hashnode* _next){
        this->next = _next;
    }
    
    hashnode(){
        this->data = "";
        this->next = NULL;
    }
    
    ~hashnode(){}
};

class hashtable{
    
private:
    hashnode* hash_node_pool;
    hashnode** hash_table_main;
    int hash_table_len, node_pool_len, node_pool_cnt;
public:
    hashtable(int hash_table_len, int node_pool_len){
        this->hash_table_len = hash_table_len;
        this->node_pool_len = node_pool_len;
        this->node_pool_cnt = 0;
        try {
            this->hash_table_main = new hashnode* [this->hash_table_len];
            memset(hash_table_main, 0, sizeof(hashnode*)* this->hash_table_len);
            this->hash_node_pool = new hashnode[this->node_pool_len];
        } catch (exception e) {
            std::cerr << "this is no space" << endl;
        }
        
    }
    
    ~hashtable(){
        delete []hash_table_main;
        delete []hash_node_pool;
    }
    
    hashnode* getNewNode(){
        if (this->node_pool_cnt == this->node_pool_len)
            return NULL;
        return &(hash_node_pool[node_pool_cnt++]);
    }
    
    static int BKDRHash(string str){
        int hash = 0, seed = 131;
        for (int i = 0; i < str.length(); i++){
            hash = hash * seed + str[i];
        }
        return hash & 0x7fffffff;
    }
    
    int getHashIndex(string str){
        if (this->hash_table_len == 0) return 0;
        return hashtable::BKDRHash(str) % this->hash_table_len;
    }
    
    bool insert(string str, bool &is_unic){
        int hash_index = this->getHashIndex(str);
        if (true == search(str)){
            is_unic = false;
            return true;
        }
        hashnode* q = this->getNewNode();
        if (q == NULL) return false;
        q->setdata(str);
        hashnode* p = this->hash_table_main[hash_index];
        q->setnext(p);
        hash_table_main[hash_index] = q;
        is_unic = true;
        return true;
        
    }
    
    bool search(string str){
        int hash_index = this->getHashIndex(str);
        hashnode* p = this->hash_table_main[hash_index];
        while(p     != NULL){
            if (p->getdate() == str) return true;
            p = p->getnext();
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    hashtable ht(100, 100);
    bool is_unic, flag;
    ht.insert("AOA", is_unic);
    cout << "insert AOA  " << is_unic <<endl;
    cout << ht.search("AOA") << endl;
    cout << ht.search("BOB") << endl;
    
    ht.insert("AOA", is_unic);
    cout << "insert AOA  " << is_unic <<endl;
    ht.insert("BBB", is_unic);
    cout << "insert BBB" << is_unic <<endl;
    flag = ht.search("BBB");
    cout << "search flag == " << flag << endl;
    
}
