#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,drink;
    float sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>drink;
        sum+=drink;
    }
    float ans=sum/n;
    cout<<ans;
    return 0;
}
