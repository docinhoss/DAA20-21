#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) ((int)((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

int v;
vector<pair<int,int>> excentricidade; // (index,maior)
auto maxSort = [](const pair<int,int> &a, const pair<int,int> &b){if(a.second > b.second) return true; else if(a.second < b.second) return false; return a.first < b.first;};

vector<int> bfs(int P, vector<vector<int>> adjList){
  vector<int> visited(v, -1);
  queue<pair<int,int>> q;
  q.push(make_pair(P, 0)); visited[P] = 0;
  int cur=0, dep=0;
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
  excentricidade.push_back(make_pair(P+1,dep));
  return visited;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int e, from, to; cin >> v >> e;
  vector<vector<int>> adj(v); vector<vector<int>> matrix(v, vector<int>(v, 0));
  for(int i=0; i<e; i++){
    cin >> from >> to;
    adj[from-1].push_back(to-1);
    adj[to-1].push_back(from-1);
  }
  for(int i=0; i<v; i++) matrix[i] = bfs(i, adj);
  sort(excentricidade.begin(), excentricidade.end(), maxSort);
  int maxi = excentricidade[0].second, mini = excentricidade[v-1].second;
  cout << maxi << "\n" << mini << "\n";
  auto it = find_if(excentricidade.begin(), excentricidade.end(), [&mini](const pair<int,int> &elem){return elem.second == mini;});
  for(auto itr = it; itr != excentricidade.end(); itr++) cout << itr->first << (((itr+1) != excentricidade.end()) ? " " : "\n");
  for(int i=0; i<v; i++) if(excentricidade[i].second == maxi) (excentricidade[i+1].second == maxi) ? cout << excentricidade[i].first << " " : cout << excentricidade[i].first; else{cout << "\n"; break;}
  return 0;
}
