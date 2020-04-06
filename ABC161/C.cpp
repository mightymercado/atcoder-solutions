#include <iostream>
#include <set>
using namespace std;
typedef long long i64;
 
int a[100];
int main() {
    i64 n, k;
    cin >> n >> k;
    set<int> v;
    i64 low = n;
    while (n) {
        if (n >= k) {
            n %= k;
            if (v.count(n)) break;
            v.insert(n);
            low = min(n, low);
        }
 
        // cout << n << endl;
        if (n < k) {
            n = k - n;
            if (v.count(n)) break;
            v.insert(n);
            low = min(n, low);
        }
    }
    cout << low << endl;
}
