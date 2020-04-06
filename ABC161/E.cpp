#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long i64;
 
const int maxn = (int) 2e5 + 1;
string s;
int n, k, c;
 
int main() {
  int n;
  cin >> n >> k >> c >> s;
  vector<int> first, last;
  for (int i = n - 1; i >= 0; ) {
    if (s[i] == 'o') {
      last.push_back(i + 1);
      if (last.size() == k) break;
      i -= c + 1;
    } else {
      i -= 1;
    }
  }
  for (int i = 0; i < n; ) {
    if (s[i] == 'o') {
      first.push_back(i + 1);
      if (first.size() == k) break;
      i += c + 1;
    } else {
      i += 1;
    }
  }
 
  reverse(last.begin(), last.end());
  if (first.size() == last.size()) {
    for (int i = 0; i < k; i++) {
      if (first[i] != last[i]) continue;
      cout << first[i] << endl;
    }
  } else if (first.size() == k) {
    for (int x : first)
      cout << x << endl;
  } else if (last.size() == k) {
    for (int x : last)
      cout << x << endl;
  }
}
