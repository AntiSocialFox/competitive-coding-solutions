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
#define l long


typedef long long int ll;

const double pi = 3.1415926535;
ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

using namespace std;

int main()
{
    sonic
    l n, tmp;
    l arr[200001], ind[200001];
    string s;
    cin >> n;
    for (long i=1; i<=n; i++) {
        cin >> tmp;
        ind[tmp]=i;
    }
    l L=1, R=n;
    for(long i=1; i<=n; i++) {
        tmp=ind[i];
        if (L==tmp) {
            s+='L';
            L++;
        } else {
            if (R==tmp) {
                s+='R';
                R--;
            }
        }
    }
    cout << s.length() << endl;
    cout << s << endl;
    return 0;
}
