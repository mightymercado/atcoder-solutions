#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5;
vector<int> adj[maxn + 1];
int dp[maxn + 1] = {0};

int dfs(int x) {
  int &m = dp[x];
  if (m) return m;
  for (int y : adj[x]) m = max(m, dfs(y) + 1);
  return m;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  for (int i = 0; i < n; i++)
    adj[n].push_back(i);
  cout << dfs(n) - 1 << '\n';
}
