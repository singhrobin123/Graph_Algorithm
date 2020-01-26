#include<bits/stdc++.h>
using namespace std;

class dfs
{
private:
    int size;
    list<int> *adj;
public:
    dfs(int);
    ~dfs();
    void add_edge(int,int);
    void dfs_(bool[],int);
    void dfs_util();
};

dfs::dfs(int s)
{  this->size = s;
   adj=new list<int>[s];
}

dfs::~dfs()
{
}

void dfs::add_edge(int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void dfs::dfs_(bool vis[],int s){
     vis[s]=true;
     cout<<s<<" ";
     for(auto i:adj[s]){
         if(!vis[i])
          dfs_(vis,i);
     }
}

void dfs::dfs_util(){
    bool *vis = new bool[this->size];
    memset(vis,false,sizeof(vis));

    for(int i=1;i<this->size;i++){
        if(!vis[i]){
            dfs_(vis,i);
        }
    }
}
signed main(){
      dfs g(4);
      g.add_edge(1,2);
      g.add_edge(1,3);
      g.add_edge(2,3);
      g.add_edge(0,3);
      g.dfs_util();
return 0;
}