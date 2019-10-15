#include <bits/stdc++.h>

using namespace std;

int n;
int h[30],g[30];
int counter=0;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i]>>g[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(h[i]==g[j]){counter++;}
        }
    }
    cout<<counter;
    return 0;
}
