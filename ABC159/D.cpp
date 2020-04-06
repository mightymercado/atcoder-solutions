#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;
 
const int maxn = 2e5;
int occur[maxn + 1] = {0};
int a[maxn], b[maxn];
int main() {
  int n;
  cin >> n;
 
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    occur[a[i]] += 1;
  }
 
  copy(a, a + n, b);
  sort(b, b + n);
  
  i64 total = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && b[i - 1] == b[i]) continue;
    total += (i64) occur[b[i]] * (occur[b[i]] - 1) / 2;
  }
 
  for (int i = 0; i < n; i++) {
      cout << total 
        - (i64) occur[a[i]] * (occur[a[i]] - 1) / 2 
        + (i64) (occur[a[i]] - 1) * (occur[a[i]] - 2) / 2 
      << '\n';
  }
}
