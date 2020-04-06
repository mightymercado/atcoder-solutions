#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;

const int maxn = 100;
const int maxv = 1e3;
i64 dp[maxv * maxn + 1] = {0};
i64 w[maxn];
i64 v[maxn];

int main() {
  int n, W;
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = maxn * maxv; j >= v[i]; j--) {
      if (j != v[i] && dp[j - v[i]] == 0) 
        continue;
      i64 sol = dp[j - v[i]] + w[i];
      dp[j] = dp[j] == 0 ? sol : min(dp[j], sol);
    }
  }
  for (int i = maxn * maxv; i >= 0; i--) {
    if (dp[i] > 0 && dp[i] <= W) {
      cout << i << ' ' << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
}
