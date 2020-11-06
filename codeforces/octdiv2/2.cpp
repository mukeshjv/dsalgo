#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int >
#define vll vector<ll>
#define vvi vector< vector< int > >
#define big (long)1e9 + 7

int power(int x,  int y, int p)  
{  
    int res = 1;    
  
    x = x % p; 
   
    if (x == 0) return 0; 
  
    while (y > 0)  
    {  
       
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 
void bins(int n, int x, int pos, ll& ans, int& cnt, int start, int end){
	int middle = (start+end)/2;
	if(middle == pos)
		return;
	cnt++;
	if(middle<pos){
		ans = ((ans%big)*((x-1)%big))%big;
		bins(n,x,pos,ans,cnt, middle+1, end);
	}
	else{
		ans = ((ans%big)* ((n-x)%big))%big;
		bins(n,x,pos,ans,cnt,start, middle-1);
	}
}
void solve(){
	ll n,x,pos;
	cin >> n >> x >> pos;
	ll ans = 1;
	int cnt = 1;
	
	bins(n,x,pos,ans,cnt,0,n-1);
	ans = ((ans%big)*((power(n-cnt,n-cnt,big))%big))%big;
	cout << ans << endl;

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