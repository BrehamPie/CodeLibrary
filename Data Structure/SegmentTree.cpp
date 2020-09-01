#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
struct SegmentTree
{
    ///Change data according to problem
    struct data
    {
        int sum;
        data():sum(0){};
    };
    int N;
    vector<data>st;
    vector<bool>isLazy;
    vector<int>lazy;

    void init(int n)
    {
        N=n;
        st.resize(4*N+5);
        isLazy.assign(4*N+5,false);
        lazy.assign(4*N+5,0);
    }
    ///Merge the child according to problem
    void merge(data &cur,data &l,data &r)
    {
        cur.sum=l.sum+r.sum;
    }
    void propagate(int C,int L,int R)
    {
        if(L!=R)
        {
            isLazy[C<<1]=1;
            isLazy[C<<1|1]=1;
            lazy[C<<1]+=lazy[C];
            lazy[C<<1|1]+=lazy[C];
        }
        st[C].sum+=(R-L+1)*lazy[C];
        lazy[C]=0;
        isLazy[C]=false;
    }
    void build(int C,int L,int R)
    {
        if(L==R){st[C].sum=arr[L];return ; }
        int M =(L+R)>>1;
        build(C<<1,L,M);
        build(C<<1|1,M+1,R);
        merge(st[C],st[C<<1],st[C<<1|1]);
    }
    data Query(int C,int L,int R,int i,int j)
    {
        if(isLazy[C]) propagate(C,L,R);
        if(j<L || i>R) return data();
        if(i<=L && R<=j) return st[C];
        int M =(L+R)>>1;
        data left = Query(C<<1,L,M,i,j);
        data right = Query(C<<1|1,M+1,R,i,j);
        data cur;merge(cur,left,right);
        return cur;
    }
    data pQuery(int C,int L,int R,int idx)
    {
        if(isLazy[C]) propagate(C,L,R);
        if(L==R) return st[C];
        int M = (L+R)>>1;
        if(idx<=M) return pQuery(C<<1,L,M,idx);
        else return pQuery(C<<1|1,M+1,R,idx);
    }
    void Update(int C,int L,int R,int i,int j,int val)
    {
        if(isLazy[C]) propagate(C,L,R);
        if(j<L || i>R) return ;
        if(i<=L && R<=j)
        {
            isLazy[C]=1;
            lazy[C] = val;
            propagate(C,L,R);
            return ;
        }
        int M=(L+R)>>1;
        Update(C<<1,L,M,i,j,val);
        Update(C<<1|1,M+1,R,i,j,val);
        merge(st[C],st[C<<1],st[C<<1|1]);
    }
    void pUpdate(int C,int L,int R,int idx,int val)
	{
		if(isLazy[C])
			propagate(C, L, R);
		if(L == R)
		{
			isLazy[C] = 1;
			lazy[C] = val;
			propagate(C, L, R);
			return;
		}
		int M = (L + R)>>1;
		if(idx <= M)
			pUpdate(C<<1,L,M,idx,val);
		else
			pUpdate(C<<1|1,M+1,R,idx,val);
		merge(st[C], st[C<<1], st[C<<1|1]);
	}

	data query(int idx)
	{
		return pQuery(1,1,N,idx);
	}

	data query(int l, int r)
	{
		return Query(1,1,N,l, r);
	}

	void update(int idx, int val)
	{
		pUpdate(1,1,N,idx, val);
	}
	void update(int l, int r, int val)
	{
		Update(1,1,N,l, r, val);
	}
};

int main()
{

}
