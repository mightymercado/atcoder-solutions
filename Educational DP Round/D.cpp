#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;

const int maxn = 100;
const int maxw = 1e5;
i64 dp[maxw + 1] = {0};
i64 w[maxn];
i64 v[maxn];

int main() {
  int n, W;
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  dp[0] = 0; // max value when weight is x
  for (int i = 0; i < n; i++) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  sort(dp, dp + (W + 1));
  cout << dp[W] << endl;
}
