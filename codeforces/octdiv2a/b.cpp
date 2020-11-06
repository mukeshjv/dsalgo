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
	string s;
	cin >> s;
	int cnt = 0;
	int left = 0;
	int right = 1;
	for(int i = 0;i<s.length();i++){
		if(s[i]==s[i+1]){
			if(s[i]=='0'){
				int j = i+1;
				while(s[j]!='1'){
					j++;
				}
				
			}
		}
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