#include <iostream>
using i64 = long long;
using namespace std;

class ModInt {
public:
  int value;
  static const int mod = 1e9 + 7;
  ModInt(int value = 0) {
    this->value = normalize(value);
  }  
  ModInt& operator+=(const ModInt& other) {
      this->value = (*this + other).value;
      return *this;
  }
  ModInt& operator-=(const ModInt& other) {
      this->value = (*this - other).value;
      return *this;
  }
  ModInt& operator*=(const ModInt& other) {
      this->value = (*this * other).value;
      return *this;
  }
  ModInt& operator/=(const ModInt& other) {
      this->value = (*this / other).value;
      return *this;
  }
  int inverse(int a) const {
    int m = mod;
    int u = 0, v = 1;
    while (a != 0) {
        int t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
  }
  ModInt operator+(const ModInt &R) const {
    return ModInt(ModInt::normalize(this->value + R.value));
  } 
  ModInt operator-(const ModInt &R) const {
    return ModInt(ModInt::normalize(this->value - R.value));
  } 
  ModInt operator*(const ModInt &R) const {
    return ModInt(ModInt::normalize((i64) this->value * R.value));
  } 
  ModInt operator/(const ModInt &R) const {
    return ModInt(ModInt::normalize((i64) this->value * inverse(R.value)));
  }
  int normalize(i64 value) const {
    while (value < 0) value += mod;
    value %= mod;
    return value;
  }
};

ostream& operator<<(ostream& os, ModInt const &m) {
  os << (m.value);
  return os;
}

istream& operator>>(istream& is, ModInt& r) {
    is >> r.value;
    r.value = r.normalize(r.value);
    return is;
}

const int maxn = 1e5;
ModInt dp[maxn + 1][100][2] = {0};
int main() {
  string s;
  int d;
  cin >> s >> d;
  reverse(s.begin(), s.end());
  dp[0][0][0] = 1;
  dp[0][0][1] = 1;
  for (int i = 1; i <= s.size(); i++) {
    for (int rem = 0; rem < d; rem++) {
      for (int limit = false; limit <= 1; limit++) {
        int max_digit = limit ? s[i - 1] - '0' : 9;
        for (int j = 0; j <= max_digit; j++) {
          int new_rem = (rem + j) % d;
          int new_limit = limit ? j == max_digit : false;
          dp[i][rem][limit] += dp[i - 1][new_rem][new_limit];
        }
      }
    }
  }
  
  cout << dp[s.size()][0][1] - 1 << '\n';
}
