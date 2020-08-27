#include<bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int>par, rnk, sz;///par-parent ,rnk - upper bound of tree depth,sz-size of component
    int c;///Total components.
    DSU(int n): par(n+1),rnk(n+1,0),sz(n+1,0),c(n)
    {
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int root(int i){return par[i]==i?i:(par[i]=root(par[i]));}
    bool same(int a,int b) {return root(a)==root(b);}
    int get_size(int a) {return sz[root(a)];}
    int components(){return c;}
    int marge(int a,int b)
    {
        a=root(a),b=root(b);
        if(a==b) return -1;
        c--;
        if(rnk[a]>rnk[b]) swap(a,b);
        par[a]=b;
        sz[b]+=sz[a];
        if(rnk[a]==rnk[b]) rnk[b]++;
        return b;
    }
};

int main()
{
    int n;
    cin>>n;
    DSU dsu(n);
    vector<int>ruts;
    vector<pii>dlt;
    for(int i=1;i<n;i++)
    {
        int u,v;
        int p=dsu.marge(u,v);
        if(p+1) continue;
        dlt.pb({u,v});
    }
    bool vis[n+1];
    for(int i=1;i<=n;i++)
    {
        int u=dsu.root(i);
        if(vis[u]) continue;
        ruts.pb(u);
    }
    vector<pii>ans;
    while(dsu.components()>1)
    {
        ans.pb({dlt.back().ff,dlt.back().ss});
        dlt.pop_back();
        int u=ruts.back();
        ruts.pop_back();
        int v=ruts.back();
        int x=dsu.marge(u,v);
        ruts.pb(x);
    }
    cout<<ans.size()/2<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i].ff<<' '<<ans[i].ss<<(i%2?'\n':' ');
}
