#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int >
#define vll vector<ll>
#define vvi vector< vector< int > >
#define deb(x) cout << #x << "=" << x << endl;
#define fo(i,n) for(i=0;i<n;i++)
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define pb push_back
#define itrs(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;

void solve(){
	int i,j,n,m,k;
	cin >> n >> k;	
	ll sum = 0, var;
	int mod = ceil((double)n/2);
	
	ll first_ele = (mod - 1)*k;
	ll last_ele = (n - mod);
	int cnt1 = 0;
	int cnt2 = 0, flag = 0;
	fo(i,k*n){
		cin >> var;
		cnt2++;
		if(cnt1 == first_ele){
			sum += var;
			flag = 1;
			cnt2 = 0;
		}
		cnt1++;
		if(flag == 1 and cnt2 == last_ele+1){
			cnt2 = 0;
			sum += var;
		}
		
		
	}
	cout << sum << endl;
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}