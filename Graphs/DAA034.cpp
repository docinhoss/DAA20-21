#include <bits/stdc++.h>

using namespace std;

struct edge{
	int from, to, cost;
};

int v, e;
vector<edge> edges;

void solve(int node){
	vector<int> d(v,INT_MAX); d[node] = 0;
	int x = -1;
	for(int j=0; j<v; j++){
		x = -1;
		for(int i=0; i<e; i++)
			if(d[edges[i].from] < INT_MAX)
				if(d[edges[i].to] > d[edges[i].from] + edges[i].cost){
					d[edges[i].to] =  max(INT_MIN, d[edges[i].from] + edges[i].cost);
					x = edges[i].to;				
				}	
	}
	if(x == -1) cout << "impossivel\n";
	else cout << "possivel\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int c; cin >> c;
	
	while(c--){
		cin >> v >> e;
		int from, to, cost;
		edges = vector<edge>(e);
		for(int i=0; i<e; i++){
			cin >> from >> to >> cost;
			edges[i].from = from;
			edges[i].to = to;
			edges[i].cost = cost;
		}
		solve(0);
	}
	return 0;
}
