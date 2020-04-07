#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
#include <set>
#include <array>
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

template<class T, int N>
using A = array<T, N>;

template<class T, int N, int M>
struct mat : A<A<T, N>, M> {
    using A<A<T, N>, M>::A;
    using A<A<T, N>, M>::size;
    template<class U> mat(vector<vector <U>>& a){
      for (int i = 0; i < a.size(); i++) 
        for (int j = 0; j < a[0].size(); j++)
          (*this)[i][j] = a[i][j];
    }
    void unit(int v) {
      for (int i = 0; i < min(height(), width()); i++)
        (*this)[i][i] = v;
    }
    void zero() { 
      for (int i = 0; i < height(); i++)
        for (int j = 0; j < width(); j++) 
          (*this)[i][j] = 0;
    }
    mat(int v = 0) { 
      if (v > 0) unit(v);
    }
    int height() const {
      return size();
    }
    int width() const { 
      return (*this)[0].size();
    }
    T sum() const {
      T tot = 0;
      for (int i = 0; i < height(); i++) {
        for (int j = 0; j < width(); j++) {
          tot += (*this)[i][j];
        }
      }
      return tot;
    }
    mat operator+(const mat &r) const {
      assert(height() == r.height() && width() == r.width());
      mat res = mat();
      res.zero();
      for (int i = 0; i < height(); i++) 
        for (int j = 0; j < width(); j++)
          res[i][j] = (this)[i][j] + r[i][j];
      return res;
    }
    mat operator-(const mat &r) const {
      assert(height() == r.height() && width() == r.width());
      mat res = mat();
      res.zero();        
      for (int i = 0; i < height(); i++) 
        for (int j = 0; j < width(); j++)
          res[i][j] = (this)[i][j] - r[i][j];
      return res;
    }
    mat operator*(const mat &r) const {
      assert(width() == r.height());
      mat res = mat();
      res.zero();
      for (int i = 0; i < height(); i++)
        for (int j = 0; j < r.width(); j++)
          for (int k = 0; k < width(); k++)
            res[i][j] += (*this)[i][k] * r[k][j];
      return res;
    }
    mat &operator+=( mat &r) { 
      return *this = *this + r;
    }
    mat &operator-=( mat &r) {
      return *this = *this - r;
    }
    mat &operator*=( mat &r) {
      return *this = *this * r;
    }
    mat operator^(i64 n) const {
      assert(height() == width());
      mat x = *this;
      mat r(1);
      while (n) {
          if (n & 1) r *= x;
          x *= x;
          n >>= 1;
      }
      return r;
    }
};

template<typename T, int H, int W> ostream &operator<<(ostream &os, mat<T, H, W> vec) { 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) { 
      os << vec[i][j];
    }
    os << endl;
  }
  return os;
}

const int maxn = 21;
int n;
mat<ModInt, 50, 50> a;

int main() {
  int n;
  i64 k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  cout << (a^k).sum() << endl;
}
