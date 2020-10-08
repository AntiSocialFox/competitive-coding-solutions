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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input_stream;

    int t = 1; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> speed(n);
        fo(i, n) cin >> speed[i];

        vector< vector<float> > timings(n, vector<float>(n));
        vector< vector<bool> > infections(n, vector<bool>(n, false));
        set<float> meetings;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) infections[i][j] = true;
                if(speed[i] != speed[j])
                {
                    float time = float(i - j) / float(speed[j] - speed[i]);
                    meetings.insert(time);
                    if(time > 0) timings[i][j] = time;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(auto time : meetings)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        if(timings[j][k] == time)
                        {
                            infections[i][j] = infections[i][j] || infections[i][k];
                            infections[i][k] = infections[i][j] || infections[i][k];
                        }
                    }
                }
            }
        }

        int low = INT_MAX, high = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(infections[i][j]) count++;
            }
            low = min(low, count);
            high = max(high, count);
        }

        cout << low << " " << high << endl;
    }
    return 0;
}
