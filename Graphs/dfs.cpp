#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 25

using namespace std;

int n;
bool adj[MAX][MAX];
bool visited[MAX];

void dfs(int v){
  cout << "dfs(" << v << ")\n";
  visited[v] = true;
  for(int i=1; i<=n; i++){
    if(adj[v][i] && !visited[i]) dfs(i);
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int e, a, b;

  cin >> n >> e;
  for(int i=0; i<e; i++){
    cin >> a >> b;
    adj[a][b] = adj[b][a] = true;
  }
  
  dfs(4);

  return 0;
}
