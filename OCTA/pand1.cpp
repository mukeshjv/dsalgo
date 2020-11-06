#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int flag = 0;
		ll n;
		cin >> n;
		vector<int> v;
		if(log2(n)==0){
			cout << "-1" << endl;
			continue;
		}
		for(int i=0;i<n;i++){
			if(i==0) cout << "2 ";
			if(i==1) cout << "3 ";
			if(i==2) cout << "1 ";
			else if(log2(i+1)==0){
				cout << i+2 << " " << i+1 << " ";
				i++;
			}
			else cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}