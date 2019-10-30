#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin>>n;
    cout<<max(max(n/10,((n/100)*10)+n%10),n);
    return 0;
}
