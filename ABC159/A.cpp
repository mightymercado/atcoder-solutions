#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using i64 = unsigned long long;
using namespace std;
 
int main() {
  int n, m;
  cin >> n >> m;
  cout << n * (n - 1) / 2 + (m * (m - 1)) / 2 << endl;
}
