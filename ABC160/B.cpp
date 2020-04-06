#include <iostream>
#include <vector>
using i64 = unsigned long long;
using namespace std;
 
int main() {
  i64 n;
  cin >> n;
  i64 p = (n / 500) * 1000 + (n % 500) / 5 * 5;
  printf("%lld\n", p);
}
