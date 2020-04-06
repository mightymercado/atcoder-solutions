#include <iostream>
using namespace std;
 
int a[100];
int main() {
    int n, m;
    cin >> n >> m;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += a[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * 4 * m >= tot) x++;
    }
    cout << (x >= m ? "Yes" : "No") << endl;
}
