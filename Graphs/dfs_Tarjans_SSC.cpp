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

int v, e, index, k;
int num[MAX], low[MAX];
bool adjMatrix[MAX][MAX], inStack[MAX];
stack<int> s;

vector<int> CFC;

void dfs(int node){
  num[node] = low[node] = (++index); s.push(node); inStack[node] = true;
  for(int i=1; i<=v; i++){
    if(adjMatrix[node][i] && num[i] == 0){
      dfs(i);
      low[node] = min(low[node],low[i]);
    }else if(adjMatrix[node][i] && inStack[i]){
      low[node] = min(low[node], num[i]);
    }
  }
  //We are in root of strongly connected component
  if(num[node] == low[node]){
    int i=0; 
    CFC.clear();
    do{
      i = s.top(); s.pop(); inStack[i] = false;
      CFC.push_back(i);
    }while(i != node);
    cout << "Strongly Connected Component = {";
    for(i=0; i<sz(CFC); i++){
      if(i+1 == sz(CFC)) cout << CFC[i];
      else cout << CFC[i] << ",";
    }
    cout << "}\n";
  }
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
  for(int i=1; i<=v; i++){
    if(num[i] == 0) dfs(i);
  }
   
  return 0;
}
