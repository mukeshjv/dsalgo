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
vll prime;
void solve(){
	long long i,j,n,m, flag;
	cin >> n;
	vll B;
	fo(i,n){
		cin >> m;
		B.pb(m);
	}
    i = 2;
    ll cnt;
    if(prime.size()==0){
        i = 2;
        cnt = 0;
    }
    else{
        i = *(prime.end()-1) + 1;
        cnt = prime.size();
    }
    while(cnt<n){
        flag = 1;
        for(int x = 2;x*x<=i;x++){
            if(i%x==0){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            prime.pb(i);
            cnt++;
        }
        i++;
    }
    // for(auto x: prime)
    //     cout << x << " ";
    // cout << endl;
	vll A(B.size(),0);
	for(i = 0;i<n;i++){
        A[i] = max(prime[i], prime[B[i]-1]);
        A[B[i]-1] = A[i];
    }
	for(auto x: A)
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