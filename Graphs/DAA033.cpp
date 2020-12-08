#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) ((int)((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

map<string,int> m;

struct edge{
  string from, to;; double w;
  edge(string from, string to, double w): from(from), to(to), w(w){}
  bool operator < (const edge & e) const{
    return w > e.w;
  }
};

double Dijkstra(vector<vector<edge>> adjList, string from, string to){
  int n = sz(adjList);
  vector<double> dist(n, DBL_MAX);
  dist[m.find(from)->second] = 0;
  priority_queue<edge> p; p.push(edge(from, from, 0));
  while(!p.empty()){
    edge e = p.top(); p.pop();
    if(e.w > dist[m.find(e.to)->second]) continue;
    for(int i=0; i<sz(adjList[m.find(e.to)->second]); i++){
      edge ne = adjList[m.find(e.to)->second][i];
      if(dist[m.find(ne.to)->second] > dist[m.find(ne.from)->second] + ne.w){
        dist[m.find(ne.to)->second] = ne.w = dist[m.find(ne.from)->second] + ne.w;
        p.push(ne);
      }
    }
  }
  return (dist[m.find(to)->second] == DBL_MAX) ? -1 : dist[m.find(to)->second];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int v, e; cin >> v >> e;
  string from, to; cin >> from >> to;
  string a, b; double w;
  vector<vector<edge>> adj(v);

  for(int i=0, j=0; i<e; i++){
    cin >> a >> b >> w;
    if(m.find(a) == m.end()){
      m.insert(pair<string,int>(a, j++));
    }
    if(m.find(b) == m.end()){
      m.insert(pair<string,int>(b, j++));
    }
    adj[m.find(a)->second].push_back(edge(a,b,w));
    adj[m.find(b)->second].push_back(edge(b,a,w));
  }
  cout << Dijkstra(adj, from, to) << "\n";
  return 0;
}
