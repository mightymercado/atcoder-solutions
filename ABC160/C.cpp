#include <iostream>
#include <vector>
#include <algorithm>
using i64 = unsigned long long;
using namespace std;
 
const int maxn = 2e5;
int a[maxn];
int n, k;
 
int compute(int i) {
  if (i > 0) {
    return a[i] - a[i - 1];
  } else {
    return a[i] + k - a[n - 1];
  }
}
int main() {
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n == 2) {
    cout << min(a[1] - a[0], a[0] + k - a[1]) << endl;
    return 0;
  }
  int b = 0;
  for (int i = 1; i < n; i++) {
    if (compute(b) < compute(i)) {
      b = i;
    }
  }
  cout << k - compute(b) << endl;
}
