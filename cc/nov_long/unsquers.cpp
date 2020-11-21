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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;
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

void solve(){
	int i,j,n,m,q,s;
	cin >> n >> q >> s;
	vi h;
	fo(i,n){
		cin >> m;
		h.pb(m);
	}
	vector<vi> dp(n, vi(n,0));
	vi maxcol(n,0);
	for(i = n-1;i>=0;i--){
		int maxi = h[i];
		dp[i][i] = 1;
		for(j = i+1;j<n;j++){
			if(h[j]>maxi){
				dp[i][j] = dp[i][j-1] + 1;
				maxi = h[j];
			}
			else
				dp[i][j] = dp[i][j-1];	
			if(dp[i][j]>maxcol[j])
				maxcol[j] = dp[i][j];
			else
				dp[i][j] = maxcol[j];
			
		}
		
	}
	// fo(i,n){
	// 	fo(j,n)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	int  x, y, l, r, maxlen, lastans = 0;
	fo(i,q){
		maxlen = 0;
		cin >> x >> y;
		l = (x + s*lastans - 1)%n ;
		r = (y + s*lastans -1)%n ;
		if(l>r)
			swap(l,r);
		lastans = 0;
		for(j = l;j<=r;j++){
			lastans = max(lastans, dp[j][r]);
		}
		cout << lastans << endl;
	}

}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	fastio
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}