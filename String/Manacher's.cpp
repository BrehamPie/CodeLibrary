#include<bits/stdc++.h>
using namespace std;
///Find longest palindromic substring
struct Manacher
{
    string T;
    vector<int>P;
    int len;
    void init(string str)
    {
        T+='#';
        for(char c:str)
        {
            T+=c;T+='#';
        }
        len = T.size();
        P.resize(T.size());
    }
    void build(string str)
    {
        init(str);
        int c=0,r=-1,rad;
        ///c -center of currently known palindrome
        ///r-rightmost boundary of palindrome centered at c
        ///rad-radius of the currently known palindrome
        for(int i=0;i<len;i++)///i can never be on left of c
        {
            if(i<=r) rad = min(P[2*c-i],r-i);///if i<=r it will be at least equal to P[i']
            else rad=0;
            while(i+rad<len && i-rad>=0 && T[i-rad]==T[i+rad]) rad++;
            P[i] = rad;
            if(i+rad-1>r)
            {
                c=i;
                r=i+rad-1;
            }
        }
        ///if i is odd then the palindrome is of odd length
        ///else it is of even length .

    }
};

int main()
{

}
