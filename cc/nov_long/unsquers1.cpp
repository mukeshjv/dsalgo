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
#define N 1000010
// #define endl cout << "\n";
struct bnode{
	int val;
	bnode *left, *right;
	bnode(int x) : val(x), left(NULL), right(NULL) {}
};
struct node{
	int val;
	vi adj;
	node(int x, int n) : val(x) {}
};
int lis(vi &vec, int l, int r, vi& dp)
{
	int global_max = INT_MIN;
	int maxi;
	for (int i = l; i <= r; i++)
	{
		maxi = 0;
		for (int j = i - 1; j >= l; j--)
		{
			if (vec[j] < vec[i] and dp[j] > maxi)
				maxi = dp[j];
		}
		dp[i] = maxi + 1;
		global_max = max(global_max, dp[i]);
	}
	return global_max;
}
void solve(){
	int i,j,q,s,n,m;
	cin >> n >> q >> s;
	vi h;
	vector<pair<int, int>> p;
	fo(i, n){
		cin >> m;
		h.pb(m);
		p.pb({m, i});
	}
	vi dp(h.size(),0);
	lis(h,0, n-1, dp);
	vi dp2(h.size(),0);
	int maxi = INT_MIN;
	for(i = 0;i < n;i++){
		maxi = max(maxi, dp[i]);
		dp2[i] = maxi;
	}
	int x, y, l, r, last = 0;
	fo(i,q){
		cin >> x >> y;
		l = (x + s * last - 1) % n;
		r = (y + s * last - 1) % n;
		if (l > r)
			swap(l, r);
		if(dp[l] == dp2[l]){
			last = 1;
			
		}
		cout << last << endl;
	}
}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}