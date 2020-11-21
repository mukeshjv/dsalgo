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
	int c0, c1, h;
	cin >> n >> c0 >> c1 >> h;
	string s;
	cin >> s;
	int one = 0, zero = 0;
	for(auto x: s){
		if(x == '0')
			zero ++;
		else
			one ++;
	}
	if(h >= abs(c0 - c1))
		cout << (c0*zero) + (c1*one) << endl;
	else{
		if(c1<c0)
			cout << c1*one + (c1+h)* zero << endl;
		else
			cout << c0*zero + (c0+h)* one << endl;
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