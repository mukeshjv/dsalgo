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

int comparenode(pair<ll, int> a, pair<ll, int> b){
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
void solve(){
	int i,j,n,m;
	ll w;
	cin >> n >> w;
	vector<pair<ll, int>> weights;
	ll var;
	fo(i,n){
		cin >> var;;
		weights.pb({var, i+1});
	}
	sort(itrs(weights), comparenode);
	i = n-1;
	m = 0;
	ll capacity = 0;
	stack<ll> s;
	while(capacity < ceil((double)w/2) and i>=0){
		if(weights[i].first + capacity <= w){
			m++;
			capacity += weights[i].first;
			s.push(weights[i].second);
		}
		i--;
	}
	if(capacity>=ceil((double)w/2)){
		cout << m << endl;
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
	else{
		cout << "-1" << endl;
	}
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