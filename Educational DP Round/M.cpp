#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
using i64 = long long;
using namespace std;


class ModInt {
public:
  int value;
  static const int mod = 1e9 + 7;
  ModInt() : value(0) {}
  ModInt(int value) {
    this->value = normalize(value);
  }  
  ModInt operator+(ModInt const &other) {
    return ModInt(normalize(this->value + other.value));
  }
  ModInt operator-(ModInt const &other) {
    return ModInt(normalize(this->value - other.value));
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

const int maxn = 100;
const int maxk = 1e5;
int a[maxn];
ModInt dp[maxn + 1][maxk + 1];
ModInt prefix[maxn + 1][maxk + 1];

int main() {
  int n, K;
  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  dp[0][0] = 1;
  
  for (int i = 0; i <= K; i++) 
    prefix[0][i] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= K; j++) {
      int end = j - min(j, a[i]);
      dp[i][j] = prefix[i - 1][j] - (end ? prefix[i - 1][end - 1] : 0);
      prefix[i][j] = (j ? prefix[i][j - 1] : 0) + dp[i][j];
    }
  }
  cout << dp[n][K] << '\n';
}
