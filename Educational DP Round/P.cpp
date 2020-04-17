
#include <cstdio>
#include <numeric>
#include <cmath>
#include <assert.h>
#include <deque>
#include <iostream>
#include <queue>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <bitset>
#include <array>
#define loop(i, n) for (int i = 0; i < n; i++)
#define testcase int _t; cin >> _t; while (_t--)
#define all(x) (x).begin(), (x).end()
using i64 = long long;
using namespace std;
 
void yes(bool y) {
  cout << (y ? "YES\n" : "NO\n");
}
 
template<typename T>
ostream& operator<<(ostream& os, vector<T> const &v) {
  for (T x: v) {
    os << x << ' ';
  }
  cout << '\n';
  return os;
}
 
template<typename T>
istream& operator>>(istream& is, vector<T> &v) {
  for (T &x: v) {
    is >> x;
  }
  return is;
}

const int maxn = 1e5;

vector<int> adj[maxn];
const int mod = 1e9 + 7;
const int white = 0;
const int black = 1;
bitset<int(1e5)> vis;
vector<int> adj2[maxn];
int dp[maxn][2];

void reroot(int x, int p) {
  if (p != -1) adj2[p].push_back(x);
  vis[x] = 1;
  for (int y : adj[x]) if (!vis[y]) {
    reroot(y, x);
  }
}

int dfs(int x, int pc) {
  if (dp[x][pc] != -1) return dp[x][pc];
  int b_ways = pc == black ? 0 : 1;
  int w_ways = 1;
  for (int y : adj2[x]) {
    if (pc == white) {
      b_ways = (i64) b_ways * dfs(y, black) % mod;
      w_ways = (i64) w_ways * dfs(y, white) % mod;
    } else {
      w_ways = (i64) w_ways * dfs(y, white) % mod;
    }
  }

  return dp[x][pc] = (b_ways + w_ways) % mod;
}


int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  reroot(0, -1);
  memset(dp, -1, sizeof dp);
  cout << dfs(0, white) <<  '\n';
  
}
