#include<iostream>
#include<queue>
#include <stack>
using namespace std;
const int maxN = 100;

struct Node{
    int x;
    int y;
    int steps;
    Node *father;
    Node(int _x, int _y, int _steps){
        x = _x;
        y = _y;
        steps = _steps;
    }
    
};

struct ress{
    int x;
    int y;
    ress(int _x, int _y){
        x = _x;
        y = _y;
    }
};
queue<Node*> que;

bool check[maxN][maxN];
bool flag;
int beginx, beginy, endx, endy;
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
bool jugdeEdge(int x, int y)
{
    return (x < 9) && (0 <= x) && (y < 9) && (0 <= y) && !(check[x][y]);
}
Node* dfs(int x, int y,  int steps){
    Node *tmp = new Node(x ,y , steps) ;
    que.push(tmp);
    while(!que.empty()){
        
        Node* t = que.front();

        que.pop();
        if (t->x == endx && t->y == endy)
            return  t;
        x = t->x;
        y = t->y;
        for (int i = 0; i < 8; i++)
        {
            
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];

            if (jugdeEdge(tmpx,tmpy))
            {

                check[tmpx][tmpy] = true;
                Node *tmp2 = new Node(tmpx ,tmpy , t->steps +1);
                tmp2->father = t;
                que.push(tmp2);
            }
        }
    }
    return NULL;
};

int main(){
    
    
    cin >> beginx >> beginy >> endx >> endy;
    flag = false;
    
    memset(check, false,sizeof(check));
    
    
    Node* res = dfs(beginx, beginy , 0);
    stack<ress> sta;
    while(true){
        ress tmp(res->x, res->y);
        sta.push(tmp);
        if (res->steps == 0)
            break;
        res = res->father;
    }
    while(!sta.empty()){
        ress tmp = sta.top();
        sta.pop();
        cout << tmp.x << " " << tmp.y << endl;
    }
    
    
    
    
}