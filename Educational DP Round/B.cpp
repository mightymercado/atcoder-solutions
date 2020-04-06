#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;

const int maxn = 1e5;
i64 h[maxn], dp[maxn];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> h[i];
  dp[0] = 0;
  for (int i = 1; i < n; i++) {
    dp[i] = 2e9;
    for (int j = 1; j <= min(i, k); j++) {
      dp[i] = min(
        dp[i],
        dp[i - j] + abs(h[i] - h[i - j]));
    }
  }
  cout << dp[n - 1] << '\n';
}
