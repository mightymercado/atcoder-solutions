#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
using i64 = long long;
using namespace std;

const int maxn = 3000;
i64 a[maxn];
i64 dp[maxn + 2][maxn + 2];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  for (int i = n; i >= 1; i--)
    for (int j = i + 1; j <= n; j++) 
      dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
  cout << dp[1][n] << '\n';
}
