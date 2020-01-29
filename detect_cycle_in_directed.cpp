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

class detect_cycle_in_directed
{
private:
    int size;
    vector<int> *adj;
public:
    detect_cycle_in_directed(int);
    ~detect_cycle_in_directed();
    bool dfs(int,vector<bool>&,vector<bool>&);
    bool dfs_();
    void add_edge(int,int);
};

detect_cycle_in_directed::detect_cycle_in_directed(int s)
{
    this->size=s;
    adj=new vector<int>[s];
}

detect_cycle_in_directed::~detect_cycle_in_directed()
{
}

void detect_cycle_in_directed::add_edge(int u,int v){

    adj[u].push_back(v);
}

bool detect_cycle_in_directed::dfs(int v,vector<bool>&vis,vector<bool>&track){

    if(!vis[v]){
        vis[v] = true;
        track[v]=true;
        for(auto i:adj[v]){
            if(!vis[i] and dfs(i,vis,track))
              return true;
            else if(track[i])
             return true;
        }

    }
    track[v]=false;
    return false;
}
bool detect_cycle_in_directed::dfs_(){
    vector<bool> vis(this->size,false);
    vector<bool> track(this->size,false);
    for(int i=0;i<this->size;i++)
        if(dfs(i,vis,track))
        return true;
    return false;
}

int main()
{   
    detect_cycle_in_directed g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    if(g.dfs_()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0;

}