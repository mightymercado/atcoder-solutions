#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
// using i64 = unsigned long long;
using namespace std;
 
 
int main() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n / 2; i++) {
    if (s[i] != s[n - 1 - i]) { cout << "No\n"; return 0;}
  }
  for (int i = 0; i < n / 2 / 2; i++) {
    if (s[i] != s[n / 2 - 1 - i]) { cout << "No\n"; return 0;}
  }
  cout << "Yes\n";
}
