#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 27

using namespace std;

bool adj[MAX][MAX], visited[MAX];
list<int> store;

void dfs(int v){
  visited[v] = true;
  rep(i,0,26){
    if(!visited[i] && adj[v][i]) dfs(i);
  }
  store.push_front(v);
}

int sComparator(string s, string s1){
  int len = min(s.length(), s1.length());
  rep(i,0,len){
    if(s[i] != s1[i]) return i;
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  string words[n];

  rep(i,0,n){
    cin >> words[i];
  }
  rep(i,0,n){
    if(i+1 == n) break;
    int idx = sComparator(words[i], words[i+1]);
    if(idx >= 0){
      adj[words[i][idx]-'A'][words[i+1][idx]-'A'] = true;
    }
  }
  rep(i,0,26) rep(j,0,26)
      if(!visited[i] && adj[i][j]) dfs(i);
  
  for(int x : store) cout << (char)('A'+ x);
  cout << "\n";

  return 0;
}
