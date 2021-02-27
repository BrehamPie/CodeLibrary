#include<bits/stdc++.h>
using namespace std;
struct Kuhn
{
    vector<vector<int>>adj;
    vector<int>vis,match;
    int cur;
    int n;
    Kuhn(int n):n(n),adj(n+1),vis(n+1),match(n+1){}
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }
    int dfs(int u)
    {
        if(vis[u]==cur) return 0;
        vis[u]=cur;
        for(int v:adj[u])
        {
            if(!match[v] || dfs(match[v]))
            {
                match[u]=v;
                match[v]=u;
                return 1;
            }
        }
        return 0;
    }
    int max_match()
    {
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            cur++;ans+=dfs(i);
        }
        return ans;
    }
};

int main()
{
    /*
        -> Complexity O(V * min(BPM^2, E)).
        -> Left nodes - 1,2, ... , n . Right rest.(n+1,n+2...
        -> No default constructor.Call with total node number.
    */
    int n,m,k;
    cin>>n>>m>>k;
    Kuhn kh(n+m);
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        v+=n;
        kh.addEdge(u,v);
    }
    int ans = kh.max_match();
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        if(kh.match[i]) cout<<i<<' '<<kh.match[i]-n<<endl;
}
