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
    //FASTIO;
    int lo = 0, hi = 1000;
    LL base, height, side, ans;
    // get side of square
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        string ans;
        cout<<"? "<<mid<<" "<<0<<"\n";
        cin>>ans;
        fflush(stdout);
        if(ans == "YES") lo = mid;
        else hi = mid - 1;
    }
    side = 2 * lo;

    // get base of triangle
    lo = 0; hi = 1000;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        string ans, ans1;
        cout<<"? "<<mid<<" "<<side<<"\n";
        cin>>ans;
        fflush(stdout);
        if(ans == "YES") lo = mid;
        else hi = mid - 1;
    }
    base = lo;

    // get height of triangle
    lo = side; hi = 1000;
    while (lo < hi){
        int mid = (lo + hi + 1) / 2;
        string ans, ans1;
        cout<<"? "<<0<<" "<<mid<<"\n";
        cin>>ans;
        fflush(stdout);
        if(ans == "YES") lo = mid;
        else hi = mid - 1;
    }
    height = lo - side;

    ans = (side * side) + (base * height);
    cout<<"! "<<ans;
    NEWLINE;
    return 0;
} 
