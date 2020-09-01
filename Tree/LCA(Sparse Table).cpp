#include<bits/stdc++.h>

using namespace std;
struct LCA
{
    vector<vector<int>>dp;
    vector<vector<int>>adj;///Node starts from 1.(always remember)
    vector<int>level;
    int lg;
    void init(int n)
    {
        lg=ceil(log2(n));
        dp.assign(lg+1,vector<int>(n+1,0));
        adj.assign(n+1,vector<int>());
        level.assign(n+1,0);
    }
    void dfs(int u)
    {
        for(int i=1;i<=lg;i++)
            dp[i][u]=dp[i-1][dp[i-1][u]];
        for(int v:adj[u])
        {
            if(dp[0][u]==v) continue;
            level[v]=level[u]+1;
            dp[0][v]=u;
            dfs(v);
        }
    }
    int lca(int u,int v)
    {
        if(level[v]<level[u]) swap(u,v);
        int dif = level[v]-level[u];
        for(int i=0;i<=lg;i++)
            if((dif>>i)&1) v =dp[i][v];
        for(int i=lg;i>=0;i--)
            if(dp[i][u]!=dp[i][v])
                u=dp[i][u],v=dp[i][v];
        return u==v?u:dp[0][u];
    }
    int dis(int u,int v)
    {
        return dis[u]+dis[v]-2*dis[lca(u,v)];
    }
};

int main()
{

}
