#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= k) {
            ans += 1;
        }
        else {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] <= k) {
            ans += 1;
        }
        else {
            break;
        }
    }
    cout << (ans == n * 2 ? ans / 2 : ans) << endl;

    return 0;
}
