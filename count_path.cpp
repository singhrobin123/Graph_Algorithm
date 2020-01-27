#include<bits/stdc++.h>
using namespace std;

class count_path
{
private:
    int size;
    list<int> *lis;
public:
    count_path(int);
    ~count_path();
    void add_edge(int,int);
    void dfs(int,int,vector<bool>&,int&);
    int solve(int,int);
};

count_path::count_path(int s)
{
    this->size=s;
    lis=new list<int>[s];
}

count_path::~count_path()
{
}

void count_path::add_edge(int u,int v){

    lis[u].push_back(v);
    //lis[v].push_back(u);
}

int count_path::solve(int x,int y){
        int path=0;
        vector<bool> vis(this->size,false);
        dfs(x,y,vis,path);
    return path;

}

void count_path::dfs(int s,int d,vector<bool>& vis,int& path){
         
         if(s==d)
           path++;
         else{
             vis[s]=true;
             for(auto i:lis[s]){
                 if(!vis[i]){
                     dfs(i,d,vis,path);
                 }
             }
         }
        vis[s]=false;
}

signed main(){

      count_path g(4);
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(0, 3); 
    g.add_edge(2, 0); 
    g.add_edge(2, 1); 
    g.add_edge(1, 3); 
  
    int s = 2, d = 3; 
    cout << g.solve(s, d); 
  
    return 0; 
}