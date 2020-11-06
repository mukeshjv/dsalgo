#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int >
#define vll vector<ll>
#define vvi vector< vector< int > >

bool isPrime(int n) 
{ 
    
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
void solve(){
	int n;
	cin >> n;
	vector<int> a(n,0);
	vector<vector<int > >vec(n,a);
	// for(auto x: vec){
	// 		for(auto i: x)
	// 			cout << i << " ";
	// 		cout << endl;
	// }
	int mid = int((n-1)/2);
	if(n%2==0){
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i==j or i==(n-j-1))
					vec[i][j] = 1;
				else
					vec[i][j] = 0;
			}
		}
	}
	else{
		for(int i = 0;i<n;i++){
			for(int j = 0;j<n;j++){
				if(i==j or (n-j-1)==i)
					vec[i][j] = 1;
				else
					vec[i][j] = 0;
				if(i==mid and j==mid){
					vec[i][j-1] = 1;
					vec[i-1][j] = 1;
				}
			}
		}
	}
	for(auto x: vec){
			for(auto i: x)
				cout << i << " ";
			cout << endl;
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