#include <bits/stdc++.h>

#define trav(a,x) for(auto& a : x)
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define sz(v) (int)(((v).size()))

#define LOWER(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define UP(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define RDUPLICATE(s) s.erase(unique(s.begin(), s.end()), s.end()) 

#define NOT_VISITED -1

using namespace std;

int index;
vector<vector<int>> adjList;
bool root;
vector<int> num, low;
stack<pair<int,int>> component;
set<int> artpoints;

void dfs(int node, int prev){
  num[node] = low[node] = (++index);
  pair<int,int> edge;
  
  for(auto &child : adjList[node]){
    if(prev != child && num[child] < num[node]) component.push({node,child});
    if(num[child] == NOT_VISITED){
      dfs(child, node);
      low[node] = min(low[node],low[child]);
      if(low[child] >= num[node]){
        if(num[node] == 1 && root == false){
          root = true;
        }else{
          artpoints.insert(node+1);
        }
        int cnt=0;
        do{
          cnt++;
          edge = component.top(); component.pop();
          cout << edge.first+1 << " " << edge.second+1 << "\n";
        }while(edge.first != node || edge.second != child);
        if(cnt == 1) cout << edge.second+1 << " " << edge.first+1 << "\n";
      }
    }else if(child != prev){
      low[node] = min(low[node], num[child]);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int v, e; cin >> v >> e;
  int from, to;
  
  adjList = vector<vector<int>>(v);
  num = low = vector<int>(v,NOT_VISITED);
  
  rep(i,0,e){
    cin >> from >> to;
    adjList[from-1].push_back(to-1);
    adjList[to-1].push_back(from-1);
  }
  cout << "\n\n"; 
  dfs(0, NOT_VISITED);
  for(auto &e : artpoints){
    cout << e << " ";
  }
  cout << "\n";
  return 0;
}

