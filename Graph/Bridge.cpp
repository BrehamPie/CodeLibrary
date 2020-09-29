#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int mx =100005;
using pii = pair<int,int>;
vector<int>adj[mx];
vector<pii>edges;
struct Bridge
{
    vector<int>tin,low,vis;
    int tyme,n;
    set<pii>bridges;
    void init(int N)
    {
        n=N;
        tin.assign(n+1,-1);
        low.assign(n+1,-1);
        vis.assign(n+1,0);
        tyme = 0;
    }
    void dfs(int u,int p=-1)
    {
        vis[u]=1;
        tin[u] = low[u] = tyme++;
        for(int v:adj[u])
        {
            if(v==p) continue;
            if(vis[v]) low[u] = min(low[u],tin[v]);
            if(!vis[v])
            {
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(low[v]>tin[u])
                bridges.insert({min(u,v),max(u,v)});///If bidirectional graph.else insert(u,v).
            }
        }
    }
    set<pii> find_bridge()
    {
        for(int i=1;i<=n;i++)
            if(!vis[i])
                dfs(i);
        return bridges;
    }
};
int main()
{
    /**
        Important tips:
        *  2 edge connected components: no bridge in graph
        *  if there are bridge SCC is not possible
    */
}
/*Problem:
 1.https://codeforces.com/contest/118/problem/E
 */
