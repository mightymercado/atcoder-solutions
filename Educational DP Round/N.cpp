#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
using i64 = long long;
using namespace std;

const int maxn = 4e2;
int n;
i64 a[maxn + 1];
i64 p[maxn + 1] = {0};
i64 dp[maxn + 1][maxn + 1] = {0};

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = p[i - 1] + a[i];
  }
  auto range = [](int i, int j) {
    return p[j] - p[i - 1];
  };

  for (int i = n; i >= 1; i--) {
    for (int j = i; j <= n; j++) {
      if (i == j) { dp[i][j] = 0; continue; }
      dp[i][j] = 1e18;
      for (int split = i + 1; split <= j; split++) {
        dp[i][j] = min(dp[i][j], 
          dp[i][split - 1] + dp[split][j] + range(i, j));
      }
    }
  }
  cout << dp[1][n] << '\n';
}
