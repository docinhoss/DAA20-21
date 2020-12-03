#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) ((int)((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

int v;

vector<int> bfs(int P, vector<vector<int>> adjList){
  vector<int> visited(v, -1);
  queue<pair<int,int>> q;
  q.push(make_pair(P, 0)); visited[P] = 0;
  int cur, dep;
  while(!q.empty()){
    pair<int,int> p = q.front(); q.pop();
    cur = p.first, dep = p.second;
    for(int i=0; i<sz(adjList[cur]); i++){
      if(visited[adjList[cur][i]] == -1){
        q.push(make_pair(adjList[cur][i], dep+1));
        visited[adjList[cur][i]] = dep+1;
      }
    }
  }
  return visited;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int e; cin >> v >> e;
  int from, to;
  vector<vector<int>> adj(v);
  for(int i=0; i<e; i++){
    cin >> from >> to;
    adj[from-1].push_back(to-1);
    adj[to-1].push_back(from-1);
  }
  
  vector<int> p = bfs(0, adj);
  for(auto &x : p){
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
