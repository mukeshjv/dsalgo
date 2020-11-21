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
	int i,j,n,m;
	int k;
	cin >> n >> k;
	string s;
	cin >> s;
	int mcnt = 0;
	if(k==0){
		cout << "0" << endl;
		return;
	}
	vi ls;
	int shieldcnt = 0;
	fo(i,n){
		ls.pb(shieldcnt);
		if(s[i]==':')
			shieldcnt++;
	}
	shieldcnt = 0;
	int flag = 0;
	queue<int> iron;
	queue<int> magnets;
	fo(i,n){
		switch (s[i])
		{
		case 'I':
			{
				while(!magnets.empty()){
					int idx = magnets.front();
					int cost = (k+1) - (i-idx) - (ls[i] - ls[idx]);
					if(cost>0){
						mcnt++;
						magnets.pop();
						flag = 1;
						break;
					}
					magnets.pop();
				}	
				if(flag==0)
					iron.push(i);
				else
					flag = 0;
			}
			break;
		case 'M':
			{
				while(!iron.empty()){
					int idx = iron.front();
					int cost = (k+1) - (i-idx) - (ls[i] - ls[idx]);
					if(cost>0){
						mcnt++;
						flag = 1;
						iron.pop();
						break;
					}
					iron.pop();
				}
				if(flag==0)
					magnets.push(i);
				else
					flag = 0;
				
			}
			break;
		case 'X':
			{
				while(!iron.empty())
					iron.pop();
				while(!magnets.empty())
					magnets.pop();
			}
			break;
		default:
			break;
		}
	}
	cout << mcnt << endl;
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