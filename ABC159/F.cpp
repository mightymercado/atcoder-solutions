#include <iostream>
#include <vector>
using i64 = unsigned long long;
using namespace std;
 
int main() {
  i64 n;
  cin >> n;
  int sagot = 0;
  for (int i = 2; i <= n / i; i++) {
    vector<i64> d;
    if (n % i == 0) {
      d.push_back(i);
      if (n / i > i) {
        d.push_back(n / i);
      }
    }
    for (int x : d) {
      i64 t;
      for (t = n; t % x == 0; t /= x); 
      if (t % x == 1) sagot++;
    }
  }
  for (int i = 2; i <= (n - 1) / i; i++) {
    if ((n - 1) % i == 0) {
      sagot++;
      if ((n - 1) / i > i) {
        sagot++;
      }
    }
  }
  printf("%d\n", sagot + (n > 2) + 1); // +1 for k = n - 1
}
