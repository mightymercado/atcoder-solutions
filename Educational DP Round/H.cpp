#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e3;
string g[maxn];
int dp[maxn + 1][maxn + 1] = {0};
int main() {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; i++)
    cin >> g[i];
  dp[1][1] = 1;
  for (int i = 1; i <= h; i++)
    for (int j = 1 + (i == 1); j <= w; j++)
      if (g[i - 1][j - 1] == '.')
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
  cout << dp[h][w] << '\n';
}
