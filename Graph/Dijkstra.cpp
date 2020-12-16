#include<bits/stdc++.h>
#define mem(x,i)    memset(x,i,sizeof(x))
using namespace std;
using ll = long long;
const int mx = 1e5+5;
const int INF = 0x3f3f3f3f;
vector<pair<int,ll>>adj[mx];
int dis[mx];
int path[mx];
bool vis[mx];
bool Dijkstra(int src,int des)
{
    mem(vis,0);
    mem(dis,INF);
    multiset< pair<ll,int> >ms;
    ms.insert({0,src});
    while(!ms.empty())
    {
        auto x = *ms.begin();
        ms.erase(ms.begin());
        int u = x.second;
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto y:adj[u])
        {
            int v= y.first;
            ll cost = y.second;
            if(dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                path[v]=u;
                ms.insert({dis[v],v});
            }
        }
    }
    ///Path Print
    if(!vis[des]) return 0,puts("-1");
    vector<int>road;
    int v= des;
    while(path[v]) {road.push_back(v);v=path[v];}
    road.push_back(src);
    reverse(road.begin(),road.end());
    for(int x:road) cout<<x<<' ';cout<<endl;
    return 1;
}
int main()
{

}
