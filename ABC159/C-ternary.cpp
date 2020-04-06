#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
// using i64 = unsigned long long;
using namespace std;
 
int L;
 
double calc(double i) {
  double j = (L - i) / 2;
  double k = (L - i) / 2;
  return i * j * k;
}
 
int main() {
 
  cin >> L;
  double s = 1;
  double e = L - 2;
  while (abs(s - e) > 1e-7) {
      double m1 = s + (e - s) / 3;
      double m2 = e - (e - s) / 3;
      double r1 = calc(m1);
      double r2 = calc(m2);
      if (abs(r1 - r2) <= 1e-7) {
        s = m1;
        e = m2;
        break;
      } else if (r1 < r2) {
        s = m1;
      } else if (r1 > r2) {
        e = m2;
      }
  }
  cout.precision(20);
  cout << calc(s) << endl;
}
