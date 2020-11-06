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
	//int i,j,n,m;
	ll n,ans = 1;
	cin >> n;
	vector<ll> vec;
	ll var;
	for(ll i = 0;i<n;i++){
		cin >> var;
		vec.pb(var);
		if(vec[i]<vec[i-1] and i>0){
			//deb(var)
			ans++;
		}
	}
	cout << ans << endl;
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