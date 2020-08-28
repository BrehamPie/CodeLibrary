#include<bits/stdc++.h>
using namespace std;
struct Trie
{
    struct node
    {
        int next[26];
        int cnt,fin;
        node():cnt(0),fin(0)
        {
            for(int i=0;i<26;i++) next[i]=-1;
        }
    };
    vector<node>data;
    Trie(){data.push_back(node());}
    void key_add(string str)
    {
        int cur=0;
        for(char c:str)
        {
            int id=c-'a';
            if(data[cur].next[id]==-1)
            {
                data[cur].next[id]=data.size();
                data.push_back(node());
            }
            cur=data[cur].next[id];
            data[cur].cnt++;
        }
        data[cur].fin++;
    }
    int key_search(string str)
    {
        int cur=0;
        for(char c:str)
        {
            int id=c-'a';
            if(data[cur].next[id]==-1) return 0;
            cur=data[cur].next[id];
        }
        return data[cur].fin;
    }
    void key_delete(string str)
    {
        int cur=0;
       for(char c:str)
       {
           int id=c-'a';
           cur=data[cur].next[id];
           data[cur].cnt--;
       }
       data[cur].fin--;
    }
    bool key_remove(string str)
    {
        if(key_search(str)) return key_delete(str),1;
        return 0;
    }
};

int main()
{

}
