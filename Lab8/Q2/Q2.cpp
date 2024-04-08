#include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    ll minCost(ll n, ll m, ll mask, ll prev, ll color,vector<vector<pair<ll,ll>>> &graph,vector<vector<pair<ll,ll>>> &dp)
    {
        if (mask == ((1 << n) - 1))
            return 0; 
        if(color == 0 && dp[mask][prev].first != 0) 
            return dp[mask][prev].first; 
        if(color == 1 && dp[mask][prev].second != 0) 
            return dp[mask][prev].second; 
        ll ans = INT_MAX;   
        for (ll i = 0; i < n; i++)
        {
            if(color == 1 && graph[prev][i].first && !(mask & (1<<i)))
                ans = min(ans, graph[prev][i].first + minCost(n,m,mask|(1<<i),i,0,graph,dp)); 
            if(color == 0 && graph[prev][i].second && !(mask & (1<<i)))
                ans = min(ans, graph[prev][i].second + minCost(n,m,mask|(1<<i),i,1,graph,dp)); 
        }
        if(color == 0)
            return dp[mask][prev].first = ans;
        else 
            return dp[mask][prev].second = ans;
    }

    int main()
    {
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout); 
        ll n,m; cin>>n>>m; 
        vector<vector<pair<ll,ll>>> graph(n,vector<pair<ll,ll>>(n)); 
        vector<vector<pair<ll,ll>>> dp(1<<n,vector<pair<ll,ll>>(n)); 
        for(ll i = 0; i < m; i++)
        {
            ll u,v,color,w; 
            cin>>u>>v>>color>>w;
            u--,v--;
            if(color == 0)
                graph[u][v].first = graph[v][u].first = w; 
            else
                graph[u][v].second = graph[v][u].second = w; 
        }
        ll ans = INT_MAX; 
        for(ll i = 0; i < n; i++)
        {
            ans = min(ans, minCost(n,m,1<<i,i,0,graph,dp)); 
        }
        if(ans == INT_MAX) ans = -1; 
        cout<<ans<<"\n"; 
    }
