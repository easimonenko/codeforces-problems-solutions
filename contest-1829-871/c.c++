#include <cstddef>
#include<iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    int both = 0, first = 0, second = 0;
    for (size_t i = 0; i < n; i++) {
      int m, b;
      cin >> m >> b;
      if (b == 11) {
        if (both == 0 || both > m) {
          both = m;
        }
      } else if (b == 10) {
        if (first == 0 || first > m) {
          first = m;
        }
      } else if (b == 1) {
        if (second == 0 || second > m) {
          second = m;
        }
      }
    }
    if (both == 0) {
      if (first == 0 || second == 0) {
        cout << "-1" << endl;
      } else {
        cout << first + second << endl;
      }
    } else {
      if (first == 0 || second == 0) {
        cout << both << endl;
      } else {
        cout << min(both, first + second) << endl;
      }
    }
    t--;
  }
  return 0;
}
