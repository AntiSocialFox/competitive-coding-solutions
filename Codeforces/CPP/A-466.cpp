#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b,c,d;
    cin>>n;
    cin>>m;
    cin>>a;
    cin>>b;
    c=min((n%m)*a,b);
    d=(n/m)*b+c;
    
    cout<<min(d,a*n);
    return 0;
}
