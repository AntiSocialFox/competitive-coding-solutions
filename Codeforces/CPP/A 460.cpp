#include <bits/stdc++.h>

using namespace std;

int n,m,day,counter=0;

int main(){

    cin>>n>>m;
    for(int day=1;n>0;day++){
        n--;
        counter++;
        if(day%m==0){n++;}
    }
    cout<<counter;
    return 0;
}
