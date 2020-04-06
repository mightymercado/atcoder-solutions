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
  ModInt operator-=(ModInt const &other) {
    this->value = normalize(this->value - other.value);
    return *this;
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
ModInt dp[maxk + 1];

int main() {
  int n, K;
  cin >> n >> K;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    // convert to prefix sum
    for (int j = 1; j <= K; j++) {
      dp[j] += dp[j - 1];
    }
    // compute answer based on prefix sums
    for (int j = K; j > a[i]; j--) {
      dp[j] -= dp[j - a[i] - 1];
    }
  }
  cout << dp[K] << '\n';
}
