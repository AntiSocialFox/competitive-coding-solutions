#include <cmath>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>  
#include <stack>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector<int> VI; 
typedef vector<long long> VLL;
typedef long long LL; 
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef unsigned short US;

#define F(i,L,R) for (int i = L; i < R; i++)
#define FR(i,R,L) for (int i = R; i >= L; i--)
#define FA(it, ds) for (auto it = ds.begin(); it != ds.end(); it++)
#define PB push_back
#define MP make_pair
#define ALL(A) A.begin(), A.end()
#define VIP(A) int temp; cin>>temp; A.PB(temp)
#define NEWLINE cout<<"\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL) 

 
int main(){
    FASTIO;

    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        VI ip;
        multiset <int> ans;
        F(i, 0, n){
            VIP(ip);
            auto itr = ans.upper_bound(ip[i]);
            if(ans.size() == 0 || itr == ans.end())
                ans.insert(ip[i]);
            else
                ans.erase(itr), ans.insert(ip[i]);
        }
        cout<<ans.size()<<" ";
        FA(itr, ans) cout<<*itr<<" ";
        NEWLINE;
    }
    
    return 0;
} 
