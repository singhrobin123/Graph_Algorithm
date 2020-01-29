/**
 *    author:  Robin 
 *    created: 06.12.2019 17:30:53       
**/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld      long double
#define pii     pair<long long int ,long long int>
#define pld     pair<ld ,ld>
#define F       first
#define S       second
#define mod     1000000007
#define pb      push_back
#define mp      make_pair
#define all(x)  x.begin(),x.end()
#define mset(x) memset(x, 0, sizeof(x));
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

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