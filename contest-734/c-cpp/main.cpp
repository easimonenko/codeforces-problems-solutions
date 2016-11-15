#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    int n, m, k;
    cin >> n >> m >> k;
    int x, s;
    cin >> x >> s;

    vector<pair<int, int> > ba(m);
    vector<int> a(m);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        ba[i] = make_pair(b[i], a[i]);
    }
    sort(ba.begin(), ba.end());

    vector<int> c(k);
    vector<int> d(k);
    for (int j = 0; j < k; j++) {
        scanf("%d", &c[j]);
    }
    for (int j = 0; j < k; j++) {
        scanf("%d", &d[j]);
        if (d[j] > s) {
            k = j;
            break;
        }
    }

    long long answer = ~(1LL << 63);
    for (int j = 0; j < k; j++) {
        int r = n - c[j]; // остаток зелий
        int y = x - d[j]; // остаток денег
        if (r > 0) {
            if (y > 0) {
                for (int i = 0; i < m; i++) {
                    if (ba[i].first <= y) {
                        answer = min(answer, ba[i].second * (long long)r);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else {
            answer = 0;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
