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
	long long i,j,n,m;
	cin >> n;
	vi B;
	fo(i,n){
		cin >> m;
		B.pb(m);
	}
	vll a(B.size(),0);
	ll randnum = 4e6 -1;
	priority_queue<pair<long long, long long>> pq;
	fo(i,n){
		if(B[i]==-1){
			a[i] = -1;
			continue;
		}
		if(B[i]==i+1)
			a[i] = randnum -= 2;
		else{
			pq.push(make_pair(B[i]-1, i));
			B[B[i]-1] = -1;
			a[i] = -1;
		}	
	}
	ll var = 2;
	while(!pq.empty()){
		pair<long long, long long> p = pq.top();
		pq.pop();
		if(a[p.first]==-1){
			a[p.second] = var;
			a[p.first] = 2*var;
			var = 2*var + 2;
		}
		else{
			a[p.second] = a[p.first]/2;
		}
	}
	for(auto x: a)
		cout << x << " ";
	cout << endl;
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