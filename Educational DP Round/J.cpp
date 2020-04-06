#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 300;
double dp[3 * maxn + 1][2 * maxn][maxn + 1] = {0};
int occur[3] = {0};

void test() {
  double sum = 0;
  double n = 50, e = 30;
  for (double i = 0; i <= 1000; i++) {
    sum += (n - e) / n * pow(e / n, i) * (i + 1);
  }
  cout << sum << endl;
  cout << e / (n - e) << endl;
  cout << n / (n - e) << endl;
}

int main() {
  // test();
  // return 0;
  int n;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    occur[x - 1]++;
  }
  for (int k = 0; k <= occur[2]; k++) {
    for (int j = 0; j <= occur[1] + occur[2]; j++) {
      for (int i = 0; i <= occur[0] + occur[1] + occur[2]; i++) {
        if (i == 0 && j == 0 && k == 0) continue;
        double s = i + j + k;
        dp[i][j][k] = 
          (k ? dp[i][j + 1][k - 1] * k / s : 0) +
          (j ? dp[i + 1][j - 1][k] * j / s : 0) + 
          (i ? dp[i - 1][j][k] * i / s : 0) + 
          + n / s;
          
      }
    }
  }
  cout.precision(10);
  cout << dp[occur[0]][occur[1]][occur[2]]  << '\n';
}
