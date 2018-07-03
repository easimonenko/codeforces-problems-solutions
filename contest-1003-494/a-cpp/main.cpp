#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(101);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        d[c]++;
    }

    int ans = 0;
    for (int k = 0; k <= 100; k++) {
        ans = max(d[k], ans);
    }
    cout << ans << endl;

    return 0;
}
