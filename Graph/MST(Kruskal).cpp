#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
struct Kruskal
{
    struct data
    {
        int u,v,idx;
        ll w;
        data(){}
        data(int idx,int u,int v,int w):idx(idx),u(u),v(v),w(w){}
        bool operator<(data &o)
        {
            return w<o.w;
        }
    };
    vector<data> edges;
    vector<int>par,sz;
    int components;
    void init(int n)
    {
        par.resize(n+1);
        sz.resize(n+1);
        components = n;
        for(int i=1;i<=n;i++) par[i]=i,sz[i]=1;
    }
    void addEdge(int idx,int u,int v,ll w)
    {
        data d(idx,u,v,w);
        edges.pb(d);
    }
    int root(int k)
    {
        while(k!=par[k])
        {
            par[k]=par[par[k]];
            k=par[k];
        }
        return k;
    }
    void join(int u,int v)
    {
        int r1=root(u);
        int r2=root(v);
        if(r1==r2) return;
        components--;
        if(sz[r1]>sz[r2]) swap(r1,r2);
        sz[r2]+=sz[r1];
        sz[r1]=0;
        par[r1]=par[r2];
    }
    ll mst()
    {
        sort(edges.begin(),edges.end());
        ll cost = 0;
        for(auto d:edges)
        {
            int u=d.u,v=d.v;
            ll w = d.w;
            int r1=root(u);
            int r2=root(v);
            if(r1==r2) continue;
            cost+=w;
            join(u,v);
        }
        return cost;
    }
};

int main()
{
    /*
        Create instance.
        Call init(n) where n=node number.
        Call addEdge(idx,u,v,w) to add edge.
        Call mst() to get the minimum cost.
        No adjaceny matrix created.
        components return total components.
        addEdge includes edge index too.
        sz returns size of that components.
        Node Starts from 1.
    */

    /*
        Problem: https://cses.fi/problemset/task/1675
    */
}
