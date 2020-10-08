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
    // input_stream;

    ll powers[21];
    for(int i = 0; i < 22; i++)
        powers[i] = pow(2, i);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;

        cout << "1" << " " << powers[20] << endl;
        fflush(stdout);
        ll sum; cin >> sum;
        if(sum == -1) return 0;
        sum -= (n * powers[20]);
        
        string sum_binary = bitset<21>(sum).to_string();
        reverse(sum_binary.begin(), sum_binary.end());
        
        string ans = bitset<21>(0).to_string();
        ans[0] = sum_binary[0];


        for(int i = 1; i < 20; i++)
        {
            cout << "1 " << powers[i] << endl;
            fflush(stdout);
            ll temp; cin >> temp;
            if(temp == -1) return 0;
            
            int original_bits;
            ll diff = (sum - temp);
            diff /= powers[i];
            if (n + diff == 1) original_bits = 1;
            else original_bits = (n + diff) / 2;
            if(original_bits % 2) ans[i] = '1';
            else ans[i] = '0';
        }

        reverse(ans.begin(), ans.end());
        unsigned ll decimal_answer = bitset<21>(ans).to_ullong();
        cout << "2 " << decimal_answer <<endl;
        fflush(stdout);
        int next_case; cin >> next_case;
        if(next_case == 1) continue;
        else return 0;
    }

    return 0;
} 
