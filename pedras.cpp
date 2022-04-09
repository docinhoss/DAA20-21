#include <bits/stdc++.h>

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> rocks(N);
  for (int i = 0; i < N; i++) {
    cin >> rocks[i];
  }
  int Q;
  cin >> Q;
  vector<bool> dp(Q + 1, false);
  for (int i = 1; i <= Q; i++) {
    for (int p : rocks) {
      if (dp[i]) break;
      if (i - p < 0) {
	break;
      }
      dp[i] = !(dp[i] || dp[i - p]);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
