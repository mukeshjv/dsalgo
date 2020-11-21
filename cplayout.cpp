#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define deb(x) cout << #x << "=" << x << endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define pb push_back
#define itrs(x) x.begin(), x.end()
#define PI 3.1415926535897932384626
const int mod = 1'000'000'007;

struct bnode
{
    int val;
    bnode *left, *right;
    bnode(int x) : val(x), left(NULL), right(NULL) {}
};
struct node
{
    int val;
    vi adj;
    node(int x, int n) : val(x) {}
};
void solve()
{
    int i, j, n, m;
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}