#include <cstdio>
#include <numeric>
#include <iostream>
using namespace std;

const int maxn = 2999;
double p[maxn];
double dp[maxn + 1] = {0};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int heads = i + 1; heads >= 0; heads--) {
      dp[heads] = dp[heads] * (1 - p[i]);
      if (heads > 0)
        dp[heads] += dp[heads - 1] * p[i] ; 
    }
  }
  cout.precision(10);
  cout << accumulate(dp + n / 2 + 1, dp + n + 1, 0.0) << '\n';
}
