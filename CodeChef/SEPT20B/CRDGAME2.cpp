// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define fo(i,n) for(int i = 0; i < n; i++)
#define Fo(i,k,n) for(int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define debug(x) cout << #x << "=" << x << endl
#define debug_2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int MOD = 1000000007;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}

unsigned ll fac[100001];

unsigned ll power(unsigned ll x, ll y) 
{ 
    unsigned ll res = 1;
    x = x % MOD; 
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res * x) % MOD; 
        y = y >> 1;
        x = (x * x) % MOD; 
    } 
    return res; 
} 

unsigned ll modInverse(unsigned ll n) 
{ 
    return power(n, MOD - 2); 
} 

unsigned ll nCr(unsigned ll n, ll r) 
{ 
    if (r == 0) 
        return 1; 
    return (fac[n] * modInverse(fac[r]) % MOD * modInverse(fac[n - r]) % MOD) % MOD; 
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    fac[0] = 1; 
    for (int i = 1; i <= 100001; i++) 
        fac[i] = (fac[i - 1] * i) % MOD; 

    int t = 1; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll low = 0, high = 0, answer = 0, low_ans = 0, high_ans = 0;
        map<ll, ll> frequency;
        for(ll i = 0; i < n; i++) 
        {
            ll temp; cin >> temp;
            frequency[temp]++;
        }

        auto temp = frequency.end(); temp--;
        high = (*temp).S; low = n - high;

        for(int i = 0; i < ceil(high / 2.0); i++)
            high_ans = ((high_ans % MOD) + (nCr(high, i) % MOD)) % MOD;
        
        for(int i = 0; i <= low; i++)
            low_ans = ((low_ans % MOD) + (nCr(low, i) % MOD)) % MOD;

        answer = ((low_ans % MOD) * (high_ans % MOD)) % MOD;
        answer = ((answer % MOD) * (2 % MOD)) % MOD;

        cout << answer << endl;
    }
    return 0;
}
