#include <iostream>
#include <vector>
#include <algorithm>
// using i64 = unsigned long long;
using namespace std;
 
const int maxn = 2e3;
int n, x, y;
int dist[maxn] = {0};
 
int calc(int i, int j) {
  int ret = abs(j - i); 
  ret = min(ret, abs(x - i) + 1 + abs(y - j));
  return min(ret, abs(y - i) + 1 + abs(x - j));
}
 
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) 
    for (int j = i + 1; j <= n; j++)
      dist[calc(i, j)]++;
  for (int i = 1; i <= n - 1; i++)
    cout << dist[i] << '\n';
}
