#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    string s(a + b, ' ');

    char first = '0';
    char second = '1';
    if (a < b) {
        first = '1';
        second = '0';
    }

    int i = 0;
    for (int k = 0; k < max(a, b) - x / 2 - 1; k++) {
        s[i] = first;
        i++;
    }
    for (int k = 0; k < x + 1; k++) {
        if (k % 2 == 0) {
            s[i] = first;
        }
        else {
            s[i] = second;
        }
        i++;
    }
    for (int k = 0; k < min(a, b) - x / 2 - 1; k++) {
        s[i] = second;
        i++;
    }

    cout << s << endl;

    return 0;
}
