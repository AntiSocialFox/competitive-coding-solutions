#include <bits/stdc++.h>

using namespace std;

vector<int> distances;
int x,s=0;

int main(){

    for(int i=0;i<3;i++){
        cin>>x;distances.push_back(x);
    }
    sort(distances.begin(),distances.end());
    s+=distances[2]-distances[0];
    cout<<s;
    return 0;

}
