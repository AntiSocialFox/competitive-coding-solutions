#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,points;
    cin>>n;
    cin>>points;
    int ans=0;
    int maxi=points,mini=points;
    n--;
    while(n--)
    {
        cin>>points;
        if(points<mini)
        {
            mini=points;
            ans++;
        }
        if(points>maxi)
        {
            maxi=points;
            ans++;
        }

    }
    cout<<ans;
    return 0;

}
