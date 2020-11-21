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
const long int mod2 = 4294967296;
const int mod = 1'000'000'007;

struct bnode{
	int val;
	bnode *left, *right;
	bnode(int x) : val(x), left(NULL), right(NULL) {}
};
struct node{
	ll val;
	vi adj;
	node(ll x) : val(x) {}
};

void solve(){
	int i,j,n;
    ll m;
    int q;
    cin >> n >> q;
    vector<node *> graph;
    fo(i,n){
       cin >> m;
       graph.pb(new node(m));
    }
    fo(i,n-1){
        int u,v;
        cin >> u >> v;
        graph[u-1]->adj.pb(v-1);
        graph[v-1]->adj.pb(u-1);
    }
    vector<vector<int>> path(n);
    vector<bool> visited(n, false);
    queue<pair<int, int> > que;
    vector<int> vals(n);
    vals[0] = graph[0]->val * graph[0]->val;
    que.push(make_pair(0, -1));
    path[0].pb(0);
    while(!que.empty()){
        pair<int, int> parent = que.front();
        que.pop();
        visited[parent.first] = true;
        for(auto child: graph[parent.first]->adj){
            if(!visited[child]){
                que.push({child, parent.first});
                path[child] = path[parent.first];
                path[child].pb(child);
                vals[child] = vals[parent.first] + (pow(graph[child]->val, 2));
            }
        }
    }
    // for(auto x: vals)
    //     cout << x << " ";
    // cout << endl;
    fo(i,q){
        int u,v;
        cin >> u >> v;
        ll ans = 0;
        // for(auto x: path[u-1])
        //     cout << x << " ";
        // cout << endl;
        // for (auto x : path[v - 1])
        //     cout << x << " ";
        // cout << endl;
        // for(j = 0;j<path[u-1].size();j++){
            
        //     ans += ((graph[path[u-1][j]]->val % mod2) * (graph[path[v-1][j]]->val % mod2))%mod2;
        // }
        for(j = path[u-1].size()-1;j>=0 and path[u-1][j]!=path[v-1][j];j--){
            ans += ((graph[path[u - 1][j]]->val % mod2) * (graph[path[v - 1][j]]->val % mod2)) % mod2;
            cout << "\nin here" ;
        }
        ans+= (vals[j])%mod2;
        cout << ans%mod2 << endl;
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