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
bool possible(vector<int> jobs, int time){
	int cnt = 1;
	int timetillnow = 0;
	for(auto x:jobs){
		if(timetillnow + x > time){
			timetillnow = x;
			cnt++;

		}
		else{
			timetillnow += x;
		}
	}return (cnt<=2);
}
void solve(){
	int i,j,n,m;
	cin >> n;
	//cout << n << endl;

	vi dish;
	fo(i,n){
		cin >> m;
		dish.pb(m);
	}
	sort(itrs(dish));
	if(n==1)
		cout << dish[0] << endl;
	else if(n==2)
		cout << max(dish[0], dish[1]) << endl;
	else if(n==3)
		cout << max(dish[2], dish[1]+dish[0]) << endl;
	else{
		int maxi = 0;
		int i = 2;
		while(i>=0 and maxi<=dish[3]){
			maxi += dish[i];
			i--;
		}
		int nmaxi = dish[3];
		while(i>=0){
			nmaxi+= dish[i];
			i--;
		}
		cout << max(maxi, nmaxi) << endl;
	}

}
int main(){
	freopen("input","r",stdin);
	freopen("output","w",stdout);
	int t = 1;
	cin >> t;
	//cout << t << endl;
	while(t--){
		solve();
	}
}