#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) ((int)((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

struct edge{
  int from, to, w;
  edge(int from, int to, int w): from(from), to(to), w(w){}
  bool operator < (const edge & e) const{
    return w > e.w;
  }
};

int Dijkstra(vector<vector<edge>> adjList, int from, int to){
  int n = sz(adjList);
  vector<int> dist(n, INT_MAX);
  dist[from-1] = 0;
  priority_queue<edge> p; p.push(edge(0, from-1, 0));
  while(!p.empty()){
    edge e = p.top(); p.pop();
    if(e.w > dist[e.to]) continue;
    for(int i=0; i<sz(adjList[e.to]); i++){
      edge ne = adjList[e.to][i];
      if(dist[ne.to] > dist[ne.from] + e.w){
        dist[ne.to] = ne.w = dist[ne.from] + ne.w;
        p.push(ne);
      }
    }
  }
  return (dist[to-1] == INT_MAX) ? -1 : dist[to-1];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int v, e; cin >> v >> e;
  int from, to, w; vector<vector<edge>> adj(v);

  for(int i=0; i<e; i++){
    cin >> from >> to >> w; 
    adj[from-1].push_back(edge(from-1, to-1, w));
  }
  cout << Dijkstra(adj, 1, 4) << "\n";
  return 0;
}
