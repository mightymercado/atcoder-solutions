#include <cstdio>
#include <numeric>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn = 1e2;
const int maxk = 1e5;
int a[maxn], n, k;
int who[maxk + 1];
const int taro = 0;
const int jiro = 1;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];  
  for (int s = 0; s <= k; s++) {
    who[s] = jiro;
    for (int i = 0; i < n; i++)
      if (s >= a[i] && who[s - a[i]] == jiro)
        who[s] = taro;
  }
  cout << (who[k] ? "Second" : "First") << endl;
}
