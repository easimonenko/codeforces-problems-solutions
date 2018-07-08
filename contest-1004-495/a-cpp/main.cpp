#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    int ans = 2;
    int prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
        int next;
        cin >> next;

        if (next - prev == 2 * d) {
            ans += 1;
        }
        else if (next - prev > 2 * d) {
            ans += 2;
        }

        prev = next;
    }
    cout << ans << endl;

    return 0;
}
