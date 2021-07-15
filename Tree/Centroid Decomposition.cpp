#include <bits/stdc++.h>

using namespace std;
const int NODES = 100005;
struct centroidDecomposition {
  set < int > g[NODES];
  int sub[NODES], par[NODES], level[NODES];
  int curSize;
  int d[NODES];
  int dis[20][NODES];
  centroidDecomposition() {
    memset(d, 0x3f3f3f3f, sizeof(d));
    curSize = 0;
  }
  void addEdge(int u, int v) {
    g[u].insert(v);
    g[v].insert(u);
  }
  //subtree size calculate
  int calcSize(int u, int p) {
    sub[u] = 1;
    for (int v: g[u]) {
      if (v != p)
        sub[u] += calcSize(v, u);
    }
    return sub[u];
  }
  //finding centroid
  int getCentroid(int u, int p) {
    for (int v: g[u])
      if (v != p && sub[v] > curSize / 2)
        return getCentroid(v, u);
    return u;
  }
  //set Distance for ancestors.
  void setDis(int u, int from, int par = -1, int l = 0) {
    dis[from][u] = l;
    for (int v: g[u]) {
      if (v != par) setDis(v, from, u, l + 1);
    }
  }
  //tree decomposing-structure of tree changes.
  void decompose(int u, int p, int l) {
    curSize = calcSize(u, u);
    int centroid = getCentroid(u, u);
    setDis(centroid, l);
    par[centroid] = p;
    level[centroid] = l;
    for (int v: g[centroid]) {
      g[v].erase(centroid);
      decompose(v, centroid, l + 1);
    }
    g[centroid].clear();
  }
  /*  Now the tree is already of O(logn) height.We don't need extra LCA sparse table code.
  We can just climb up.We need LCA for distance in actual tree,but only distance of centroid is needed which we can directly store.So we ignore LCA for the moment.
   */
  /* Problem Specific Functions */
};
int main() {
  /*
  -> Take Object.
  ->call addEdge(u,v)
  ->call decompose(1,-1,0)
  ->Write Functions for problem
  ->static array.So check every size value.
  */
}
