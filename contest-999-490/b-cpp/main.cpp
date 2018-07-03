#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int k = 1; k <= n / 2; k++) {
        if (n % k == 0) {
            reverse(&s[0], &s[k]);
        }
    }
    reverse(s.begin(), s.end());

    cout << s << endl;

    return 0;
}
