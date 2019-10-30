//Galatians 4:16

#include <bits/stdc++.h>

#define sonic ios_base::sync_with_stdio(false); cin.tie(NULL);
#define f(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define newline cout<<endl;
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

typedef long long int ll;

const double pi = 3.1415926535;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll i,j,k,l,n;
	cin>>n;
	ll ar[n],s=0,mx=0;
	for(i=0;i<n;i++){
		cin>>ar[i];
		s+=ar[i];
		mx=max(mx,ar[i]);
	}

	k=ceil((s*1.0)/(1.0*(n-1)));
	k=max(k,mx);
	cout<<k;
	return 0;
}

