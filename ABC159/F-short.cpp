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
ModInt dp[maxn + 1];
int a[maxn];
 
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) 
    cin >> a[i];
  ModInt ans;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = s; j >= a[i]; j--)
      dp[j] += dp[j - a[i]];
    dp[a[i]] += i;
    ans += dp[s];
  }
  cout << ans << '\n';
}
