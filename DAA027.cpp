#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 51

using namespace std;

int q;
bool adj[MAX][MAX], visited[MAX], f=true;
int aColor[MAX];

bool dfs(int v, int color){
  visited[v] = true;
  aColor[v] = color*(-1);
  for(int i=1; i<=q; i++){
    if(visited[i] && adj[v][i] && aColor[i] == aColor[v]) return false;
    if(!visited[i] && adj[v][i]){
      f = true && dfs(i, aColor[v]);
    }
  }
  return f;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, e, a, b; cin >> n;

  rep(i,0,n){
    cin >> q >> e;
    rep(i,0,e){
      cin >> a >> b;
      adj[a][b] = adj[b][a] = true;
    }
    cout << (dfs(1, -1) ? "sim" : "nao") << "\n";
    memset(visited, false, sizeof(visited)); memset(aColor, 0, sizeof(aColor)); memset(adj, false, sizeof(adj));
    f=true;
  }


  return 0;
}
