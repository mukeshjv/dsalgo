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
	int i,j,n,m;
	cin >> n;
	vi vec;
	unordered_map<int, int> umap;
	for(int i = 0;i<n;i++){
		cin >> m;
		if(umap.find(m)==umap.end())
			umap[m] = 1;
		else
			umap[m]++;
	}
	unordered_map<int, bool> vals;
	ll ans = 0;
	for(auto x: umap){
		//deb(x.first)
		int j = x.first-1;
		int i = x.first;
		while(x.second>0){
			if(!vals[i] and x.second>0){
				vals[i] = true;
				//deb(i)
				//deb(abs(x.first-i))
				ans += abs(x.first-i);
				x.second--;
			}
			if(j>=1 and !vals[j] and x.second>0){
				vals[j] = true;
				// deb(j)
				// deb(abs(x.first-j))
				ans += abs(x.first-j);
				x.second--;
			}
			j--;
			i++;
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