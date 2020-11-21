#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define deb(x) cout << #x << "=" << x << endl;
#define fo(i, n) for (i = 0; i < n; i++)
#define deb2(x, y) cout << #x <<< "," << #y << "=" << y << endl;
#define pb push_back
#define itrs(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
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
    
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll i, j, n, m, q;
        cin >> n;
        //deb(n)
        vector<ll> a;
        ll var, r;
        fo(i, n)
        {
            cin >> var;
            a.pb(var);
        }
        // for(auto x: a)
        //     cout << x << " ";
        // cout << endl;
        vector<ll> vec(n + 1, 0);
        vector<vector<ll>> dp(2, vec);
        for (i = 1; i <= n; i++) {
            if (i == n)
            {
                if (a[i - 1] % 2 == 0)
                {
                    dp[0][i] += dp[0][i - 1] + a[i - 1] - 1;
                    dp[1][i] += dp[0][i - 1] + a[i - 1];
                }
                else
                {
                    dp[0][i] += dp[0][i - 1] + a[i - 1];
                    dp[1][i] += dp[0][i - 1] + a[i - 1];
                }
                continue;
            }
            if (a[i - 1] == 1)
            {
                if (a[i - 2] % 2 == 0)
                {
                    dp[0][i - 1] -= 1;
                    dp[0][i] = dp[0][i - 1];
                    dp[1][i] = dp[0][i] + 2;
                }
                else
                {
                    dp[0][i] = dp[1][i] = dp[1][i - 1];
                }
                continue;
            }
            if (a[i - 1] % 2 == 0)
            {
                dp[0][i] += dp[0][i - 1] + a[i - 1];
                dp[1][i] += dp[0][i - 1] + a[i - 1];
            }
            else
            {
                dp[0][i] += dp[0][i - 1] + a[i - 1] - 1;
                dp[1][i] += dp[0][i - 1] + a[i - 1];
            }
        }
        // for (auto x : dp)
        // {
        //     for (auto y : x)
        //         cout << y << " ";
        //     cout << endl;
        // }
        cin >> q;
        for (i = 0; i < q; i++)
        {
            cin >> r;
            if (a[0] == 1)
            {
                ll dividend = (r / n) % mod;
                ll rem = r % n;
                if (rem == 0 or (r>n and rem==1))
                    cout << dividend << endl;
                else
                    cout << (dividend + 1) << endl;
            }
            else
            {
                ll dividend = (r / n);
                ll rem = r % n;
                if (rem == 0)
                {
                    ll ans = ((dp[0][n] % mod) * ((dividend - 1) % mod)) % mod;
                    ans += max(dp[0][n], dp[1][n]);
                    cout << ans % mod << endl;
                }
                else
                {
                    ll ans = ((dp[0][n] % mod) * ((dividend) % mod)) % mod;
                    ans += max(dp[0][rem], dp[1][rem]);
                    cout << ans % mod << endl;
                }
            }
        }
    }
}