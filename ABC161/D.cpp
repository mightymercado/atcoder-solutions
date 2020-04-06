#include <iostream>
#include <vector>
using namespace std;
typedef long long i64;
 
const int maxn = 1e5;
 
int main() {
    int k;
    cin >> k;
    if (k <= 9) {
        cout << k << endl;
        return 0;
    }
    int a[99];
    int d = 2;
    a[0] = 0;
    a[1] = 1;
    for (int _ = 0; _ < k - 10; _++) {
        int found = -1;
        for (int i = 0; i < d - 1; i++) {
            // printf("%d %d\n", a[i], a[i+1]);
            if (a[i] <= a[i + 1] && a[i + 1] - (a[i] + 1) <= 1 && a[i] < 9) {
                a[i] += 1;
                found = i;
                break;
            }
        }
        if (found == -1 && abs(a[d - 1] + 1 - a[d - 2]) <= 1 && a[d - 1] < 9) {
            a[d - 1] += 1;
            found = d - 1;
        } else if (found == -1) {
            d++;
            a[d - 1] = 1;
            found = d - 1;
        }
        for (int j = found - 1; j >= 0; j--) {
            a[j] = max(a[j + 1] - 1, 0);
        }
    }
    for (int i = d - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}
