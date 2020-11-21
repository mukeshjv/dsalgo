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
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}
void solve(){
	int i,j,n,m;
	ll var, sum = 0;
	cin >> n;
	ll maxi = 0;
	vll a(n);
	fo(i,n){
		cin >> var;
		a[i] = var;
		sum += var;
		maxi = max(maxi, var);
	}
	ll temp = sum;
	vll dp(n);
	fo(i,n){
		dp[i] = maxi - a[i];
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