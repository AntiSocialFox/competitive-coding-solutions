#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,ans=0;
    cin>>n>>m>>a>>b;
    ans+=b;
    n-=m;
    ans+=n*a;
    cout<<ans;
    return 0;

}
