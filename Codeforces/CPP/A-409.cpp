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

int main()
{
    int n,talent,prog=0,math=0,phys=0,teams;
    vi students;
    sonic
    cin>>n;
    f(i,0,n)
    {
        cin>>talent;
        if(talent==1) prog++;
        if(talent==2) math++;
        if(talent==3) phys++;
        students.pb(talent);
    }
    teams=min(prog,min(math,phys));
    cout<<teams<<endl;
    f(i,0,teams)
    {
        f(j,1,4)
        {
            f(k,0,n)
            {
                if(students[k]==j)
                {
                    cout<<k+1<<" ";
                    students[k]=0;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}

