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

LL ans = 0;

VI merge(VI left, VI right){
    VI merged;
    int nl = left.size(), nr = right.size();
    int li = 0, ri = 0;
    
    while (li < nl && ri < nr){
        if (left[li] <= right[ri]){
            merged.PB(left[li]);
            li++;
        }
        else{
            merged.PB(right[ri]);
            ri++;
            ans += left.size() - li;
        }
    }

    while (li < nl) {
        merged.PB(left[li]);
        li++;
    }

    while (ri < nr) {
        merged.PB(right[ri]);
        ri++;
    }
    return merged;
}

void mergesort(VI &a, int l , int r){
    if (l == r) return;
    int mid = (l + r) / 2;
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    
    VI left, right;
    F(i, l, mid + 1) left.PB(a[i]);
    F(i, mid + 1, r + 1) right.PB(a[i]);
    VI b = merge(left, right);
    F(i, 0, b.size()) a[l + i] = b[i];
    return;
}
 
int main(){
    FASTIO;

    VI a;
    int n;
    cin>>n;
    F(i, 0, n) {
        VIP(a);
    }
    mergesort(a, 0, n - 1);
    cout<<ans;
    NEWLINE;
    return 0;
} 
