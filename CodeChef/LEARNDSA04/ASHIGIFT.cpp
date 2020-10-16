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
#include <iomanip>
#include <bitset>

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

bool possible(LL mid, LL X, LL B, LL C, LL dishes[][2], LL clans[][3]){
	LL dish_itr = 0, clans_itr = 0;
	while(dish_itr < B && clans_itr < C){ 
        if(dishes[dish_itr][0] < clans[clans_itr][0]){
            mid -= dishes[dish_itr][1];
            dish_itr++;
            if(mid < 0) return false;
        } 
        else{
            if(clans[clans_itr][1] <= mid) mid += clans[clans_itr][2];
            clans_itr++;
        }
	}

    while(dish_itr < B){
        mid -= dishes[dish_itr][1];
        dish_itr++;
        if(mid < 0) return false;
    }

	if(mid >= 1) return true;
	else return false;
}
 
int main(){
	FASTIO;

	int t;
	cin>>t;
	while(t--){
		LL X, B, C;
		cin>>X>>B;
		LL dishes[B][2];
		LL max_people = 1;
		F(i, 0, B){
			// int temp;
			// cin>>temp;
			cin>>dishes[i][0]>>dishes[i][1];
			max_people += dishes[i][1]; 
		}
		cin>>C;
		LL clans[C][3];
		F(i, 0, C){
			//int temp;
			cin>>clans[i][0]>>clans[i][1]>>clans[i][2];
		}
		LL lo = 1, hi = max_people, ans = max_people;
		if(C != 0){
			while(lo <= hi){
				LL mid = lo + ((hi - lo) / 2);
				if(possible(mid, X, B, C, dishes, clans)){
					ans = min(ans, mid);
					hi = mid - 1;
				}
				else lo = mid + 1;
			}			
		}
		cout<<ans;
		NEWLINE;
	}
	
	return 0;
} 
