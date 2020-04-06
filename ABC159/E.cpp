#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using i64 = long long;
using namespace std;
 
string g[10];
int main() {
  int H, W, K;
  cin >> H >> W >> K;
  for (int i = 0; i < H; i++) 
    cin >> g[i]; 
  int best = H * W;
  for (int s = 0; s < (1 << (H - 1)); s++) {
    auto check = [&](int x) {
      return (s & (1 << x)) > 0;
    };
    vector<int> cuts;
    for (int i = 0; i < H - 1; i++)
      if (check(i)) 
        cuts.push_back(i);
    cuts.push_back(H - 1);
    array< vector<int>, 2> occur = {
      vector<int>(cuts.size(), 0),
      vector<int>(cuts.size(), 0)
    };
    vector<int> vcuts;
    bool possible = true;
    for (int col = 0; col < W; col++) {
      bool ok;
      int repeat = 2;
      while (repeat--) {
        ok = true;
        for (int cut = 0, row = 0; cut < cuts.size() && row < H; row++) {
          if (cuts[cut] < row) {
            cut++;
          }
          int color = g[row][col] == '1';
          if (color == 1 && occur[color][cut] + 1 > K)
            { ok = false; break; }
          occur[color][cut] += 1;
        }
        if (ok) { break; }
        if (!ok && repeat == 1) {
          vcuts.push_back(col);
          fill(occur[0].begin(), occur[0].end(), 0);
          fill(occur[1].begin(), occur[1].end(), 0);
        }
      }
      if (!ok) { possible = false; break; }
 
    }
    if (!possible)
      continue;
 
    best = min(best, (int) cuts.size() + (int) vcuts.size() - 1);
  }
  cout << best << endl;
}
