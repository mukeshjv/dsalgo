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
	cin >> n >> m;
	char temp;
	vvi vec(n, vi(m));
	fo(i,n){
		fo(j,m){
			cin >> temp;
			vec[i][j] = temp-48;
		}
	}
	// for(auto x: vec){
	// 	for(auto y: x)
	// 		cout << y << " ";
	// 	cout << endl;
	// }
	i = 0;
	j = 0;
	int sum = 0;
	int first, second, third, fourth;
	int count = 0;
	vvi ans;
	vi tmp;
	while(i<n){
		if(i==n-1 and n%2!=0)
			i--;
		j = 0;
		
		while(j<m){
			//deb(j);
			if(j==m-1 and m%2!=0)
				j--;
			first = vec[i][j];
			second = vec[i][j+1];
			third = vec[i+1][j];
			fourth = vec[i+1][j+1];
			sum = first + second + third + fourth;
			//deb(sum)
			i++;j++;
			switch(sum){
				case 4:
					cout << "\ncase 4" << endl;
					tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j+1);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
					first = 0;
					second = 0;
					fourth = 0;
					i--;j--;
					vec[i][j] = 0;
					vec[i][j+1] = 0;
					vec[i+1][j+1] = 0;
					i++;j++;
				

				case 1:
					cout << "\n case 1 " << endl;
					if(first==1){
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j+1);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
						first = 0;
						second = 1;
						fourth = 1;
						i--;j--;
						vec[i][j] = 0;
						vec[i][j+1] = 1;
						vec[i+1][j+1] = 1;
						i++;j++;
					}
					else if(second == 1){
						tmp.pb(i);
						tmp.pb(j+1);
						tmp.pb(i+1);
						tmp.pb(j);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
						second = 0;
						third = 1;
						fourth = 1;
						i--;
						j--;
						vec[i][j+1] = 0;
						vec[i+1][j] = 1;
						vec[i+1][j+1] = 1;
						i++;j++;
					}
					else if(third == 1){
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j + 1);
						tmp.pb(i + 1);
						tmp.pb(j);
						ans.pb(tmp);
						tmp.clear();
						first = 1;
						second = 1;
						third = 0;
						i--;
						j--;
						vec[i][j] = 1;
						vec[i][j+1] = 1;
						vec[i+1][j] = 0;
						i++;j++;
					}
					else{
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j + 1);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
						fourth = 0;
						first = 1;
						second = 1;
						i--;
						j--;
						vec[i][j] = 0;
						vec[i ][j+1] = 1;
						vec[i + 1][j + 1] = 1;
						i++;j++;
					}
				case 2:
					//cout << "\ncase 2 " << endl;
					if(first == 1){
							tmp.pb(i);
							tmp.pb(j + 1);
							tmp.pb(i + 1);
							tmp.pb(j);
							tmp.pb(i + 1);
							tmp.pb(j + 1);
							ans.pb(tmp);
							tmp.clear();
							second = second==0 ? 1:0;
							third = third==0 ? 1:0;
							fourth = fourth==0 ? 1:0;
							i--;
							j--;
							vec[i][j+1] = vec[i][j+1] == 0 ? 1 : 0;
							vec[i+1][j] = vec[i+1][j] == 0 ? 1 : 0;
							vec[i+1][j+1] = vec[i+1][j+1] == 0 ? 1 : 0;
							i++;j++;
					}
					else if(second == 1){
							tmp.pb(i);
							tmp.pb(j);
							tmp.pb(i+1);
							tmp.pb(j + 1);
							tmp.pb(i + 1);
							tmp.pb(j);
							ans.pb(tmp);
							tmp.clear();
							third = third==0 ? 1:0;
							fourth = fourth==0 ? 1:0;
							first = first==0 ? 1:0;
							i--;
							j--;
							vec[i + 1][j] = vec[i + 1][j] == 0 ? 1 : 0;
							vec[i + 1][j + 1] = vec[i + 1][j + 1] == 0 ? 1 : 0;
							vec[i][j] = vec[i][j] == 0 ? 1:0;
							i++;j++;
					}
					else{
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j + 1);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
						second = second==0 ? 1:0;
						fourth = fourth == 0 ? 1 : 0;
						first = first == 0 ? 1 : 0;
						i--;
						j--;
						vec[i][j+1] = vec[i + 1][j] == 0 ? 1 : 0;
						vec[i + 1][j + 1] = vec[i + 1][j + 1] == 0 ? 1 : 0;
						vec[i][j] = vec[i][j] == 0 ? 1 : 0;
						i++;j++;
					}
				
				case 3:
					//cout << "\ncase 3 " << endl;
					if(first==0){
						tmp.pb(i);
							tmp.pb(j + 1);
							tmp.pb(i + 1);
							tmp.pb(j);
							tmp.pb(i + 1);
							tmp.pb(j + 1);
							ans.pb(tmp);
							tmp.clear();
							i--;
							j--;
							vec[i][j+1] = 0;
							vec[i+1][j] = 0;
							vec[i+1][j+1] = 0;
							i++;j++;
					}
					else if(second ==0){
						tmp.pb(i);
							tmp.pb(j);
							tmp.pb(i+1);
							tmp.pb(j + 1);
							tmp.pb(i + 1);
							tmp.pb(j);
							ans.pb(tmp);
							tmp.clear();
							i--;
							j--;
							vec[i + 1][j] = 0;
							vec[i + 1][j + 1] = 0;
							vec[i][j] = 0;
							i++;j++;
					}
					else if(third == 0){
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j + 1);
						tmp.pb(i+1);
						tmp.pb(j+1);
						ans.pb(tmp);
						tmp.clear();
						i--;
						j--;
						vec[i + 1][j + 1] = 0;
						vec[i][j] = 0;
						vec[i][j+1] = 0;
						i++;j++;
					}
					else{
						tmp.pb(i);
						tmp.pb(j);
						tmp.pb(i);
						tmp.pb(j+1);
						tmp.pb(i+1);
						tmp.pb(j);
						ans.pb(tmp);
						tmp.clear();
						i--;
						j--;
						vec[i][j] = 0;
						vec[i][j + 1] = 0;
						vec[i+1][j] = 0;
						i++;j++;
					}
					break;
			}
			j++;i--;
		}
		i += 2;
	}
	cout << ans.size() << endl;
	for(auto row: ans){
		for(auto column: row){
			cout << column << " ";
		}
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