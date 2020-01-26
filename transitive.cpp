#include<bits/stdc++.h>
using namespace std;

class transitive
{
private:
    int size;
    bool **tc;
    vector<int> *adj;
public:
    transitive(int);
    ~transitive();
    void dfs(int,int);
    void transitive_();
    void add_edge(int,int);
};

transitive::transitive(int s)
{  
    this->size=s;
    adj=new vector<int>[this->size];
    tc = new bool* [this->size];
    
    for(int i=0;i<s;i++){
        tc[i]=new bool[this->size];
        memset(tc[i],false,s*sizeof(bool));
    }
}

transitive::~transitive()
{
}

void transitive:: add_edge(int v,int u){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void transitive::dfs(int i,int j){
    tc[i][j]=true;
    for(auto k:adj[j]){
        if(!tc[i][k])
         dfs(i,k);
    }
}

void transitive::transitive_(){
     for(int i=0;i<this->size;i++)
      dfs(i,i);

      for(int i=0;i<this->size;i++){
          for(int j=0;j<this->size;j++)
             cout<<tc[i][j]<<" ";
           cout<<"\n";
      }
}

signed main(){
    transitive g(6);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(0,1);
    g.transitive_();
 return 0;
}