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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> h[i];
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < n; i++) dp[i] = min(
    dp[i - 1] + abs(h[i] - h[i - 1]), 
    dp[i - 2] + abs(h[i] - h[i - 2]));
  cout << dp[n - 1] << '\n';
}
