#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;
 
const int mod = 998244353;
 
class ModInt {
public:
  int value;
  ModInt() : value(0) {}
  ModInt(int value) {
    this->value = normalize(value);
  }  
  ModInt operator+(ModInt const &other) {
    return ModInt(normalize(this->value + other.value));
  }
  ModInt& operator+=(const ModInt& other) {
      this->value = normalize(this->value + other.value);
      return *this;
}
  int normalize(i64 value) {
    while (value < 0) value += mod;
    value %= mod;
    return value;
  }
};
 
ostream& operator<<(ostream& os, ModInt const &m) {
  os << (m.value);
  return os;
}
 
const int maxn = 3000;
ModInt dp[maxn][maxn + 1][3];
int a[maxn];
 
const int R = 0; // marked R
const int L = 1; // marked L
const int notR = 2; // not marked L or R
 
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  vector<ModInt> v;
  v.push_back(3);
  for (int j = 0; j <= s; j++) {
    dp[0][j][R] = j == a[0] ? 1 : 0;
    dp[0][j][R] += j == 0 ? 1 : 0;
    dp[0][j][L] = j == 0 ? 1 : 0; 
    dp[0][j][notR] = j == a[0] ? 1 : 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= s; j++) {
      if (j >= a[i]) {
        dp[i][j][R] += dp[i - 1][j - a[i]][R];
        dp[i][j][notR] += dp[i - 1][j - a[i]][L]; 
        dp[i][j][notR] += dp[i - 1][j - a[i]][R];
        dp[i][j][R] += dp[i - 1][j - a[i]][L];
      }
      dp[i][j][R] += dp[i - 1][j][R];
      dp[i][j][R] += j == 0 ? 1 : 0;
      dp[i][j][L] += j == 0 ? 1 : 0;
      dp[i][j][notR] += dp[i - 1][j][R];
      dp[i][j][notR] += j == 0 ? 1 : 0;
      dp[i][j][notR] += dp[i - 1][j][notR];
    }
  }
  cout << dp[n - 1][s][notR] << '\n';
}
