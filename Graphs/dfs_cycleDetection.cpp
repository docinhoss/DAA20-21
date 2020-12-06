#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 26
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

int v, e;
bool adjMatrix[MAX][MAX];
int color[MAX];

void dfs(int node){
  color[node] = GREY;
  for(int i=1; i<=v; i++){
    if(adjMatrix[node][i] && color[i] == GREY) printf("Ciclo encontrado = Node(%d) -> Node(%d)\n", node, i); 
    else if(adjMatrix[node][i] && color[i] == WHITE) dfs(i);
  }
  color[node] = BLACK;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> v >> e;
  int from, to;
  
  for(int i=0; i<e; i++){
    cin >> from >> to;
    adjMatrix[from][to] = true;
  }
  for(int i=1; i<=v; i++)
    if(color[i] == WHITE) dfs(i);

  return 0;
}
