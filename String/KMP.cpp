#include<bits/stdc++.h>
using namespace std;
vector<int> fail(string &s)
{
    int n=s.size();
    vector<int>pi(n);
    for(int i=1;i<n;i++)
    {
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
int KMP(string &text,string &pattern)
{
    int m=text.size(),n=pattern.size();
    string s= pattern+'#'+text;
    vector<int>pi = fail(s);
    int occurance = 0;
    for(int i=n;i<=n+m;i++) if(pi[i]==n) occurance++;
    return occurance;
}
int main()
{
    string s,t;
    cin>>t>>s;
    cout<<KMP(t,s)<<endl;
    //Occurrence of each prefix
    vector<int>pi = fail(s);
    int n=s.size();
    vector<int>ans(n+1);
    for(int i=0;i<n;i++) ans[pi[i]]++;//initial occurrence
    for(int i=n-1;i>0;i--) ans[pi[i-1]]+=ans[i];//pi[i] also contains pi[pi[i]-1]
    for(int i=0;i<=n;i++) ans[i]++;//the actual string
}
