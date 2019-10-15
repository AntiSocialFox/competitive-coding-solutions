#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,least,temp=0;
    cin>>n>>m;
    int arr[m];
    for(int k=0;k<m;k++)
        cin>>arr[k];
   for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            if(arr[j]>arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i=0;i<m;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    least=arr[0]-arr[1];
    for(int i=1;i<m-1;i++)
    {
        if(least>arr[i]-arr[i+1])
            least=arr[i]-arr[i+1];
    }
    cout<<least;
    return 0;
}
