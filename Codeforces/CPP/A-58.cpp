#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s="hello";
    string t;
    cin>>t;
    int a=0,counter=0;
    int l=t.size();
    for(int i=0;i<l;i++)
    {
        if(s[a]==t[i])
        {
            a++;
        counter++;
        }
    }
    if(counter==5)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
 
}
