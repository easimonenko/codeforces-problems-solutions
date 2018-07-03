#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> s(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    double ans = 0.0;

    for (int i = 0; i <= n - k; i++) {
        for (int j = i + k; j <= n; j++) {
            double c = ((double)(s[j] - s[i])) / (j - i + 1);
            ans = max(ans, c);
        }
    }

    printf("%.7f\n", ans);

    return 0;
}
