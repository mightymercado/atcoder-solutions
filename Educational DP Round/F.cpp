#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;

const int maxs = 3000;
string dp[2][maxs + 1];

int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 1, k = 1; i <= s.size(); i++, k ^= 1) {
    for (int j = 1; j <= t.size(); j++) {
      auto max = [](string &a, string b) {
        a = a.size() > b.size() ? a : b;
      };
      if (s[i - 1] == t[j - 1]) 
        max(dp[k][j], dp[k ^ 1][j - 1] + s[i - 1]);
      max(dp[k][j], dp[k ^ 1][j]);
      max(dp[k][j], dp[k][j - 1]);
    }
  }
  cout << dp[s.size() & 1][t.size()] << '\n';
}
