#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    /*int ans = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        int d = r - l + 1;
        if (d % 2 == 0) {
            int p = d / 2;
            ans += p * p;
        }
        else {
            int p = d / 2;
            ans += p * (p + 1);
        }
    }
    cout << ans << endl;*/

    string ans(n, '0');
    for (int i = 1; i < n; i += 2) {
        ans[i] = '1';
    }
    cout << ans << endl;

    return 0;
}
