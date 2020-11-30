#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 101

using namespace std;

int L, C, maximum=0, c=0;
char a[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int y, int x){
  if(y < 0 || y >= L || x < 0 || x >= C) return;
  if(visited[y][x] || a[y][x] == '.') return;
  c++;
  visited[y][x] = true;
  dfs(y-1,x-1); dfs(y-1,x); dfs(y-1,x+1);
  dfs(y,x-1); dfs(y,x+1);
  dfs(y+1,x-1); dfs(y+1,x); dfs(y+1,x+1);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  string s;

  rep(i,0,n){
    cin >> L >> C;
    rep(i,0,L){
      cin >> s;
      strcpy(a[i], s.c_str());
    }
    rep(i,0,L){
      rep(j,0,C){
        if(a[i][j] == '#' && !visited[i][j]){
          dfs(i,j);
          if(c > maximum) maximum=c;
          c=0;
        }
      }
    }
    cout << maximum << "\n";
    maximum=0; memset(visited,0, sizeof(visited));
  }

    
  return 0;
}
