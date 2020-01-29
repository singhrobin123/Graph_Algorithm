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

class mother_vertex
{
private:
    int size;
    vector<int> *adj;
public:
    mother_vertex(int);
    ~mother_vertex();
    void add_edge(int,int);
    void dfs(vector<bool>&,int);
    int mother();
};

mother_vertex::mother_vertex(int s)
{
    this->size=s;
    adj=new vector<int>[this->size];
}

mother_vertex::~mother_vertex()
{
}

void mother_vertex::add_edge(int v,int u){
    adj[v].push_back(u);
}

void mother_vertex::dfs(vector<bool>&vis,int s){
          vis[s]=true;
          for(auto i:adj[s]){
              if(!vis[s])
               dfs(vis,i);
          }
}

int mother_vertex::mother(){
    
          vector<bool> vis(this->size,false);
          int mother_var=0;
          for(int i=0;i<this->size;i++){
              if(!vis[i]){
                  dfs(vis,i);
                  mother_var=i;
              }
          }
          fill(vis.begin(),vis.end(),false);
          dfs(vis,mother_var);
          for(int i=0;i<this->size;i++)
           if(!vis[i])
             return -1;
    
    return mother_var;

}

signed main(){
      
      mother_vertex g(5);
      g.add_edge(1,2);
      g.add_edge(2,3);
      g.add_edge(0,1);

      cout<<g.mother<<endl;
}