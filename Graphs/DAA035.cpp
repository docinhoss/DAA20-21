#include <bits/stdc++.h>

using namespace std;

int v;
vector<vector<bool>> d;

void solve(){
	for(int i=0; i<v; i++) d[i][i] = true;
	for(int k = 0; k < v; ++k){
		for(int i = 0; i < v; ++i){
			for(int j = 0; j < v; ++j){
				if(d[i][k] && d[k][j]) d[i][j] = true;
			}
		}
	}
	cout << "  ";
	for(int i=0; i<v; i++){
		if(i+1 == v) cout << (char)('A'+i);
		else cout << (char)('A'+i) << " ";	 
	}
	cout << "\n";
	for(int i=0; i<v; i++){
		cout << (char)('A'+i) << " ";
		for(int j=0; j<v; j++){
			if(j+1 == v) cout << d[i][j];
			else cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v;
	char from, to;
	int n;
	
	d = vector<vector<bool>>(v, vector<bool>(v, false));
	
	for(int i=0; i<v; i++){
		cin >> from >> n;
		while(n--){
			cin >> to;
			d[from-'A'][to-'A'] = true;
		}
	}
	solve();
	
	return 0;
}
