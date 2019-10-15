#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    if(s.size()!=t.size())
        return 0;
    else {
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]==t[i])
            s[i]='0';
        else s[i]='1';
    }
    }
    cout<<s;
    return 0;
}
