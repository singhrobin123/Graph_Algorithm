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

class bfs
{
private:
    int size;
    list<int> *lis;
public:
    bfs(int);
    ~bfs();
    void bfs_(int);
    void add_edge(int,int);
};

bfs::bfs(int s)
{   
    this->size=s;
    lis=new list<int> [s];
}

bfs::~bfs()
{
}

void bfs::add_edge(int v,int u){
      lis[v].push_back(u);
      lis[u].push_back(v);
}
void bfs::bfs_(int s){
      bool *vis = new bool[size];
      memset(vis,false,sizeof(vis));
      vis[s]=true;
      list<int> queue;
      queue.push_back(s);
      while (!queue.empty())
      {
          s=queue.front();
          cout<<s<<" ";
          queue.pop_front();
          for(auto i:lis[s]){
              if(!vis[i])
              {vis[i]=true;
              queue.push_back(i);}
          }
      }
      
}

signed main(){
    bfs g(4);
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2,3);
    g.add_edge(3,3);
    
    cout<<"bfs : ";
    g.bfs_(2);
    cout<<"\n";
    
 return 0;
}