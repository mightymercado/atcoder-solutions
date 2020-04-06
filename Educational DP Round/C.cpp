#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;

const int maxn = 1e5;
i64 a[maxn + 1][3] = {0}, dp[maxn + 1][3] = {0};

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) 
    for (int j = 0; j < 3; j++)
      cin >> a[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        if (j != k)
          dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][k]);
  cout << max(dp[n][0], dp[n][1]) << endl;
}
