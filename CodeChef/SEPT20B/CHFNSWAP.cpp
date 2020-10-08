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
int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}

ll sum(ll n) {return n * (n + 1) / 2;}
ll diff(ll n, ll m) {return sum(n) / 2 - sum(m);}
ll nc2(ll n) {return n * (n - 1) / 2;}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // input_stream;

    ll t = 1; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll l = 1, r = n, mid;
        ll answer = 0;
        
        if(sum(n) % 2) {cout << 0 << endl; continue;}

        while(l <= r)
        {
            mid = (l + r) / 2;
            ll gap = diff(n, mid);
            if(gap > n - 1) l = mid + 1;
            else if(gap < 0) r = mid - 1;
            else
            {
                vector<ll> queries = {diff(n, mid - 1), diff(n, mid), diff(n, mid + 1)};
                for(int i = 0; i < 3; i++)
                {
                    int curr = mid + i - 1;
                    if(queries[i] < 0 || queries[i] > n) continue;
                    if(queries[i] == 0)
                    {
                        answer += nc2(curr);
                        answer += nc2(n - (curr));
                    }
                    else if(queries[i] >= curr) answer += n - queries[i];
                    else answer += min(queries[i], n - curr);
                }
                break;  
            }
        }
        cout << answer << endl;
    }
    return 0;
}
