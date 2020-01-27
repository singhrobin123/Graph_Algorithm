#include<bits/stdc++.h>
using namespace std;

class count_node_at_given_level
{
private:
    /* data */
    int size;
    list<int> *lis;
public:
    count_node_at_given_level(int);
    ~count_node_at_given_level();
    int bfs(int,int);
    void add_edge(int,int);
};

count_node_at_given_level::count_node_at_given_level(int s)
{
        this->size=s;
        lis=new list<int>[s];
}

count_node_at_given_level::~count_node_at_given_level()
{
}

void count_node_at_given_level::add_edge(int u,int v){

    lis[u].push_back(v);
    lis[v].push_back(u);
}
int count_node_at_given_level::bfs(int le,int s){

    vector<bool> vis(this->size,false);
    vector<int> level(this->size,0);
    list<int> queue;
    queue.push_back(s);
    vis[s]=true;
    level[s]=0;
    while(!queue.empty()){

        s=queue.front();
        queue.pop_front();
        for(auto i:lis[s]){
            if(!vis[i]){
                vis[i]=true;
                queue.push_back(i);
                level[i]=1+level[s];
            }
        }
    }
    int count=0;
    for(auto i:level){
        if(i==le)
         count++;
    }
    return count;
}

signed main(){
    /* body */
}