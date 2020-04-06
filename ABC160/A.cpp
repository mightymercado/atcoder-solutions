clude <iostream>
#include <vector>
using i64 = unsigned long long;
using namespace std;
 
int main() {
  string s;
  cin >> s;
  if (s[2] == s[3] && s[4] == s[5]) cout << "Yes" << endl;
  else cout << "No" << endl;
}
