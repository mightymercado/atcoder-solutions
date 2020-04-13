#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <array>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxh = 1e5;
const int maxw = 1e5;
array<int, 2> r[3002];
int dp[3002];
int f[maxh + maxw + 1];
int fi[maxh + maxw + 1];

int pow_mod(int b, int e) {
  int r = 1;
  while (e) {
    if (e & 1) r = (i64) r * b % mod;
    e >>= 1;
    b = (i64) b * b % mod;
  }
  return r;
}

void precompute_factorials() {
  f[0] = 1;
  for (int i = 1; i <= maxh + maxw; i++) {
    f[i] = (i64) f[i - 1] * i % mod;
  }
  fi[maxh + maxw] = pow_mod(f[maxh + maxw], mod - 2);
  for (int i = maxh + maxw - 1; i >= 0; i--) {
    fi[i] = (i64) fi[i + 1] * (i + 1) % mod;
  }
}

int ways(array<int, 2> &a, array<int, 2> &b) {
  int dx = b[0] - a[0];
  int dy = b[1] - a[1];
  if (dy < 0) {
    return 0;
  }
  return (i64) f[dx + dy] * fi[dx] % mod * fi[dy] % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute_factorials();  

  int H, W, N;
  cin >> H >> W >> N;
  r[0][0] = 1;
  r[0][1] = 1;
  r[N + 1][0] = H;
  r[N + 1][1] = W;
  for (int i = 1; i <= N; i++) {
    cin >> r[i][0] >> r[i][1];
  }

  sort(r + 1, r + (N + 1));
  // cout << r[1][0] << " " << r[1][1] << "\n";
  dp[0] = 1;
  for (int i = 1; i <= N + 1 ; i++) {
    dp[i] = ways(r[0], r[i]);
    for (int j = 1; j < i; j++) {
      dp[i] = (dp[i] + mod - (i64) dp[j] * ways(r[j], r[i]) % mod) % mod;
    }
  }

  cout << dp[N + 1] << '\n';
}
