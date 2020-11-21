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
	stack<char> s1, s2;
	string s;
	cin >> s;
	int cnt = 0;
	for(auto x: s){
		if(x=='(')
			s1.push(x);
		if(x == '[')
			s2.push(x);
		if(x==')' and !s1.empty()){
			s1.pop();
			cnt++;
		}
		if(x==']' and !s2.empty()){
			s2.pop();
			cnt++;
		}
	}
	cout << cnt << endl;
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