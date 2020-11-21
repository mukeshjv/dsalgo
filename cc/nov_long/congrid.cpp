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
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define itrs(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;

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
	int i,j,n,m;
    int k;
    cin >> n >> k;
    int x,y,l,r;
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<pair<int, int>> limits;

    fo(i,k){
        cin >> x >> y >> l >> r;
        graph[x-1][y-1] = i+1;
        limits.pb(make_pair(l,r));
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