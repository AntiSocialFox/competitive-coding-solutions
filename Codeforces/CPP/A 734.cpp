#include <bits/stdc++.h>

using namespace std;

int n,acounter=0,bcounter=0;
string s;

int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){acounter++;}
        else{bcounter++;}
    }
    if(acounter > bcounter){cout<<"Anton";}
    else if(acounter < bcounter){cout<<"Danik";}
    else{cout<<"Friendship";}
    return 0;
}
