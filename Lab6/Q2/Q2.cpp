#include<bits/stdc++.h>
using namespace std;

void calc_longest_path(int v, vector<vector<int>> &adj, vector<int> &longest_path)
{
    int mx = 0; 
    for(int child: adj[v])
    {
        if(longest_path[child] == -1)
        {
            calc_longest_path(child,adj,longest_path); 
        }
        mx = max(mx, 1 + longest_path[child]); 
    }
    longest_path[v] = mx;  
}

int main()
{
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int v,e; cin>>v>>e; 
    vector<vector<int>> adj(v+1); 
    vector<int> longest_path(v+1,-1); 
    for(int i = 0; i < e; i++)
    {
        int u,v; cin>>u>>v; 
        adj[u].push_back(v); 
    }
    for(int i = 1; i <= v; i++)
    {
        if(longest_path[i] == -1)
        {
            calc_longest_path(i,adj,longest_path); 
        }
    }
    cout<<*max_element(longest_path.begin() + 1,longest_path.end()); 
}