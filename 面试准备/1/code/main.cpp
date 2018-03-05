#include <iostream>
#include <string>
#include <map>
using namespace std;
//1.给定两个数，不用比较运算符返回较大的数字     缺失
//2.给定一个数n,表示n层汉诺塔问题,请打印最优步数的所有过   缺失
//3.给定一棵二叉树的头节点head,和一个整数sum,二叉树每个节点上都,有数字,我们规定路径必须是从上往下的,求二叉树上累加和为sum的,最长路径长度
//4.给定一棵二叉树的头节点head,判断这棵树是不是平衡二叉树(判断需要什么信息，然后递归的去找）
//5.二叉树节点间距离的概念:二叉树一个节点到另一个节点间最短线路上的节点数量,叫做两个节点间的距离。给定一棵二叉树的头节点head,请返回这棵二叉树上的最大距离
//6.给定一棵二叉树的头节点head,请返回最大搜索二叉子树的大小
//7.最大子拓扑结构   缺失
//8.计算表达式   缺失
class Node{
public:
    int value;
    Node* left = NULL;
    Node* right = NULL;
    Node(int v){value=v;};
};

////////////////////////////////////////////////////////
//aux func

string getSpace(int num) {
    string space = "";

    for (int i = 0; i < num; i++) {
        space += " ";
    }
    return space;
}

void printInOrder(Node* head, int height, string to, int len) {
    if (head == NULL) {
        return;
    }
    printInOrder(head -> right, height + 1, "v", len);
    string val = to + to_string(head -> value) + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = getSpace(lenL) + val + getSpace(lenR);
    cout << getSpace(height * len) + val << endl;
    printInOrder(head -> left, height + 1, "^", len);
}


void printTree(Node* head) {
    cout << "Binary Tree:" << endl;
    printInOrder(head, 0, "H", 8);
    cout << endl;
}

////////////////////////////////////////////////////////

////////////////////problem 3/////////////////////////

int getMaxLen(Node* head, int sumVal, int preVal,int level, int maxlen, map<int, int>& mp){
    if (head == NULL){
        return maxlen;
    }
    int nowVal = preVal + head -> value;
    if (mp.count(nowVal) == 0){
        mp[nowVal] = level;
    }
    if (mp.count(sumVal - nowVal)){
        maxlen = max(maxlen, level - mp[sumVal - nowVal]);
    }
    maxlen = getMaxLen(head -> left, sumVal, nowVal, level + 1, maxlen,mp);
    maxlen = getMaxLen(head -> right, sumVal, nowVal, level + 1, maxlen,mp);
    if (mp[nowVal] == level){
        map<int,int>::iterator iter=mp.find(nowVal);
        mp.erase(iter);
    }
    return maxlen;
}
int problem3(Node* head, int sum){
    map<int,int> mp;
    mp[0] = 0;
    return getMaxLen(head,sum,0,1,0,mp);
};
//////////////////////////////////////////////////////


////////////////////problem 4/////////////////////////

int isBalance(Node* head,int level, bool& balance) {
    if (head == NULL)
        return level;
    bool leftFlag = true, rightFlag = true;
    int llevel = isBalance(head->left,level + 1,leftFlag);
    if(!leftFlag)
        return level;
    int rlevel = isBalance(head->right,level + 1,rightFlag);
    if(!rightFlag)
        return level;
    if (abs(llevel - rlevel) > 1)
        return level;
    balance = true;
    return max(llevel, rlevel);

}

int problem4(Node* head){
    bool flag = true;
    return isBalance(head,0,flag);
};
//////////////////////////////////////////////////////



////////////////////problem 5/////////////////////////
class ReturnType{
public:
    int Depth;
    int Distance;
    ReturnType(int depth, int distance){Depth = depth;Distance = distance;};
};

ReturnType* countMaxDis(Node* head,ReturnType* data) {
    if (head == NULL){

        return new ReturnType(0,0);
    }
    ReturnType* lres = countMaxDis(head -> left, new ReturnType(data -> Depth + 1, 0));
    ReturnType* rres = countMaxDis(head -> right, new ReturnType(data -> Depth + 1, 0));
    int val = lres  -> Depth+ 1 + rres -> Depth;

    return new ReturnType(max(lres -> Depth, rres -> Depth) + 1,max(max(lres -> Distance, rres -> Distance), val));
}

int problem5(Node* head){
    ReturnType *tmp = new ReturnType(0,0);
    return countMaxDis(head,tmp) -> Distance;
};
//////////////////////////////////////////////////////


////////////////////problem 6/////////////////////////
class ReturnType2{
public:
    int size;
    Node* head;
    int maxval;
    int minval;
    ReturnType2(int _size, Node* _head, int _maxval, int min_val){
        size = _size;
        head = _head;
        maxval = _maxval;
        minval = _maxval;
    };
};

ReturnType2* getSubBST(Node *head){
    if (head == NULL)
        return new ReturnType2(0,NULL,INT32_MIN,INT32_MAX);
    ReturnType2* lres = getSubBST(head -> left);
    ReturnType2* rres = getSubBST(head -> right);
    int return_size = 0;

    if (lres -> head == head -> left && rres -> head == head -> right &&
            lres -> maxval < head -> value && rres -> minval > head -> value){
        return_size = lres -> size + 1 + rres -> size;

    }
    else{

    }
    int max_size = max(max(lres -> size, rres -> size), return_size);
    Node* h = lres -> size > rres -> size ? lres -> head: rres -> head;

    if(return_size == max_size){
        h = head;
    }
    return new ReturnType2(max_size,h,min(min(lres -> minval,rres -> minval), head -> value),
                           max(max(lres -> maxval,rres -> maxval), head -> value));


}
int problem6(Node* head){
    return getSubBST(head)->size;
};
//////////////////////////////////////////////////////


int main() {
    Node *head1 = new Node(1);
    head1 -> left = new Node(2);
    head1-> right = new Node(3);
    head1-> left-> left = new Node(4);
    head1-> left-> right = new Node(5);
    head1-> right-> left = new Node(6);
    head1-> right-> right = new Node(7);
    head1-> left-> left-> left = new Node(8);
    head1-> right-> left-> right = new Node(9);
    printTree(head1);
    cout << problem5(head1) << endl;

    Node *head2 = new Node(1);
    head2-> left = new Node(2);
    head2-> right = new Node(3);
    head2-> right-> left = new Node(4);
    head2-> right-> right = new Node(5);
    head2-> right-> left-> left = new Node(6);
    head2-> right-> right-> right = new Node(7);
    head2-> right-> left-> left-> left = new Node(8);
    head2-> right-> right-> right-> right = new Node(9);
    printTree(head2);
    cout << problem5(head2) << endl;

    return 0;
}