#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define print for(int x: v) {cout << x << " ";} cout << endl;

bool isb(vector<int> v){
	for(int i = 0;i<v.size()-1;i++){
		if((v[i] & v[i+1]) == 0)
			return false;
	}
	if(v[0]==2 and v[1]==3 and  v[2]==1 and v[3]==5 and v[4]==4){
		print
	}
	return true;
}
int main(){
	
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int flag = 0;
		ll n;
		cin >> n;
		cout << "\n n is " << n << endl << endl;
		vector<int> v;
		for(int i = 0;i<n;i++){
			v.push_back(i+1);
		}
		do{
			if(isb(v)){
				flag = 1;	
			}

				//cout << "-1" << endl;
		}
		while(next_permutation(v.begin(),v.end()));
		if(flag == 0)
			cout << "-1";
	}
	return 0;
}