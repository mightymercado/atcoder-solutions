#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using i64 = unsigned long long;
using namespace std;
 
const int maxn = 2e3;
int x, y, mx[3], val;
int sup[3];
vector< array<int, 3> > apple;
 
int main() {
  cin >> sup[0] >> sup[1] >> mx[0] >> mx[1] >> mx[2];
  for (int k = 0; k < 3; k++)
    for (int i = 0; i < mx[k]; i++) {
      cin >> val;
      apple.push_back({val, k});
    }
  
  sort(apple.begin(), apple.end());
  reverse(apple.begin(), apple.end());
 
  int sz[2] = {0};
  int sz_none[2] = {0};
  i64 sum = 0;
 
  for (int i = 0; i < apple.size(); i++) {
    char* name[3] = {"red", "green", "uncolored"};
    // printf("red: %d\ngreen: %d\n", sz[0], sz[1]);
    int &color = apple[i][1];
    int &cost = apple[i][0];
    if (color <= 1) {
      if (sz[color] + 1 > sup[color]) {
        // try moving a previous uncolored apple
        if (sz_none[color] > 0 & sz[color ^ 1] + 1 <= sup[color ^ 1]) {
          sz_none[color] -= 1;
          sz_none[color ^ 1] += 1;
          sz[color ^ 1] += 1; 
          // printf("moving from %s to %s\n", name[color], name[color ^ 1]);
          // printf("0add %d to %s\n", cost, name[color]);
          sum += cost;
        } else {
          continue;
        }
      } else {
        // printf("1add %d to %s\n", cost, name[color]);
        sz[color] += 1;
        sum += cost;
      }
    } else if (sz[0] + 1 <= sup[0]) {
      sz[0] += 1;
      sz_none[0] += 1;
      // printf("2add %d to %s\n", cost, name[0]);
      sum += cost;
    } else if (sz[1] + 1 <= sup[1]) {
      // printf("3add %d to %s\n", cost, name[1]);
      sz[1] += 1;
      sz_none[1] += 1;
      sum += cost;
    } else {
      break;
    }
    
  }  
  cout << sum << endl;
}
