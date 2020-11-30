#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define MAX 3*76

using namespace std;

const int incX[] = {-1, 1, 0 ,0};
const int incY[] = {0, 0, -1, 1};

int rows, cols, cycles, grids, maxGrids, graph[MAX][MAX];
bool visited[MAX][MAX], visited_1[MAX][MAX];

bool isBound(int x, int y){
    return (x == 0 || x == rows-1 || y == 0 || y == cols-1);
}
bool isOut(int x, int y){
  return (x < 0 || x >= rows || y < 0 || y >= cols);
}
void flood_fill(int x, int y, int color){
  visited[x][y] = true, graph[x][y] = color;
  rep(i,0,4){
    int nx = x + incX[i], ny = y + incY[i];
    if(!isOut(nx,ny) && !visited[nx][ny] && !graph[nx][ny]) flood_fill(nx, ny, color);
  }
}
void dfs(int x, int y){
  grids++, visited_1[x][y] = true;
  rep(i,0,4){
    int nx = x + incX[i], ny = y + incY[i];
    if(!isOut(nx,ny) && !graph[nx][ny] && !visited_1[nx][ny]) dfs(nx,ny);
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  scanf("%d %d", &cols, &rows);
  char ch;
  cols*=3; rows*=3;
  for(int i=1; i<rows; i+=3){
    getchar();
    for(int j=1; j<cols; j+=3){
      scanf("%c", &ch);
      if(ch == '\\'){
        graph[i][j] = 1;
        graph[i-1][j-1] = graph[i+1][j+1] = 1;
        graph[i][j-1] = graph[i][j+1] = 0;
        graph[i-1][j+1] = graph[i+1][j-1] = 0;
      }else if(ch == '/'){
        graph[i][j] = 1;
        graph[i-1][j + 1] = graph[i+1][j-1] = 1;
        graph[i-1][j] = graph[i+1][j] = 0;
        graph[i][j-1] = graph[i][j+1] = 0;
        graph[i-1][j-1] = graph[i+1][j+1] = 0;
      }
    }
  }
  rep(i,0,rows){
    rep(j,0,cols){
      if(isBound(i,j) && !visited[i][j] && !graph[i][j]){
        flood_fill(i,j,2);
      }
    }
  }
  cycles=0, maxGrids=-1;
  rep(i,0,rows){
    rep(j,0,cols){
      if(!graph[i][j] && !visited_1[i][j]){
        cycles++, grids=0, dfs(i,j);
        if(grids > maxGrids) maxGrids = grids;
      }
    }
  }
  if(cycles) cout << cycles << " " << maxGrids/3 << "\n";
  else cout << "nao tem ciclos\n";
  return 0;
}
