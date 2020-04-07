#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
#include <set>
using i64 = long long;
using namespace std;

const int maxn = 2e5;
const int maxh = maxn;

template <typename T>
class Fenwick {
public:
  T t[maxn + 1] = {0};
  int n;

  Fenwick(int n) : n(n) {}

  T get(int i) {
    T s = 0;
    while (i > 0) {
      s = merge(s, t[i]);
      i -= i & -i;
    }
    return s;
  }

  void update(int i, T v) {
    while (i <= n) {
      t[i] = merge(t[i], v);
      i += i & -i;
    }
  }

  virtual T merge(T a, T b) {
    return a + b;
  }
};

template <typename T>
class MaxFenwick : public Fenwick<T> {
public:
  using Fenwick<T>::Fenwick;
  T merge(T a, T b) override {
    return max(a, b);
  }
};


int n;
int a[maxn + 1];
int h[maxn + 1];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  MaxFenwick<i64> dp(maxh + 1);
  for (int i = 0; i < n; i++) {
    dp.update(h[i], dp.get(h[i]) + a[i]);
  }
  cout << dp.get(n) << '\n';
}
