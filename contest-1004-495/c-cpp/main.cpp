#include <algorithm>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, pair<int,int>> p;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (p[a].first == 0) {
            p[a] = make_pair(i, i);
        }
        else {
            p[a] = make_pair(i, p[a].second);
        }
    }

    set<pair<int,int>> s;
    for_each(p.begin(), p.end(), [&s](auto elem) {
        s.insert(elem.second);
    });

    int ans = 0;
    for_each(s.begin(), s.end(), [&ans, &s](auto first) {
        for_each(s.begin(), s.end(), [&ans, &s, &first](auto second) {
            if (first.second < second.first) {
                ans++;
            }
        });
    });
    cout << ans << endl;

    return 0;
}
