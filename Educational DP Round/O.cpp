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

const int maxn = 21;
int n;
int a[maxn + 1][maxn + 1];
ModInt dp[1 << 21];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  
  dp[0] = 1;
  for (int b = 1; b < (1 << 21); b++) {
    int man = __builtin_popcount(b) - 1;
    for (int t = b; t; ) {
      int woman = __builtin_ctz(t);

      if (a[woman][man]) 
        dp[b] += dp[b & ~(1 << woman)];

      t &= ~(1 << woman);
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}
