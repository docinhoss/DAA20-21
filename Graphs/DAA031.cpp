#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) ((int)((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

using namespace std;

int incX[] = {-1, 0, 1, 0};
int incY[] = {0, -1, 0, 1};

int rows, cols;
queue<pair<pair<int,int>,int>> q;
bool valid(int y, int x){if(!(y < 0 || x < 0 || x >= cols || y >= rows)) return true; return false;}

vector<int> bfs(vector<vector<int>> &visited, string board[]){
  vector<int> pos;
  pair<int,int> cur; int depth;
  while(!q.empty()){
    pair<pair<int,int>, int> P = q.front(); q.pop();
    cur = P.first, depth = P.second;
    for(int i=0; i<4; i++){
      int nY = cur.first + incY[i], nX = cur.second + incX[i];
      if(valid(nY, nX) && visited[nY][nX] == -1 && board[nY][nX] != '#'){
        if(board[nY][nX] == 'A') pos.push_back(depth+1);
        q.push(make_pair(make_pair(nY,nX), depth+1));
        visited[nY][nX] = depth+1;
      }
    }
  }
  return pos;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> rows >> cols;
  string board[rows];
  vector<vector<int>> visited(rows, vector<int>(cols, -1));

  for(int i=0; i<rows; i++){
    cin >> board[i];
    for(int j=0; j<cols; j++){
      if(board[i][j] == '#'){ 
        q.push(make_pair(make_pair(i,j),0));
        visited[i][j] = 0;
      }
    }
  }
  vector<int> pos = bfs(visited, board);
  cout << pos[0] << " " << pos[sz(pos)-1] << "\n";

  return 0;
}
