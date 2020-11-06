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
int finalcnt = 0;
int minCut(string s)
{
    vector<bool> vec(s.length(), false);
    vector<vector<bool>> isp(s.length(), vec);
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0; i+gap < s.length(); i++)
        {
            if (gap == 0)
            {
                isp[i][i] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[i + 1])
                    isp[i][i+gap] = true;
            }
            else
            {
                if (s[i] == s[i + gap] and isp[i+1][i + gap - 1] == true)
                    isp[i][i + gap] = true;
            }
        }
    }
    int len = s.length();
    // for(int i = 0;i<len;i++)
    //     for(int j = 0;j<len;j++)
    //         cout << isp[i][j] << " ";
    //     cout << endl;
    
    vector<int> ans(s.length(), 0);
    ans[0] = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (!isp[0][i])
        {
            int mini = INT_MAX;
            for (int j = i; j >= 0; j--)
            {
                if (isp[j][i])
                {
                    int temp = ans[j - 1];
                    mini = min(mini, temp);
                }
            }
            ans[i] = mini + 1;
        }
    }
    return ans[s.length() - 1];
}

int main(){
    string s = "rgmqh8m3xZcxxyZKNNoFXIPW2i0hNcCjsH3kTMEKOHr";
    cout << minCut(s);
}

//56 30 14 7 3 2 6 22 25 45 34 51 54 52 78 66 61 58 57 59 63 76 
