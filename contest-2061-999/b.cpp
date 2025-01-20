#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    int sideward = 0;
    for (size_t i = n - 1; i >= 1; i--) {
      if (a[i] == a[i - 1]) {
        sideward = a[i];
        a[i] = 0; a[i - 1] = 0;
        break;
      }
    }

    if (sideward == 0) {
      cout << "-1" << endl;
    } else {
      sort(a.begin(), a.end());

      int top = 0, bottom = 0;
      for (size_t i = n - 1; i >= 3; i--) {
        if (a[i - 1] + 2 * sideward > a[i]) {
          top = a[i - 1];
          bottom = a[i];
          break;
        }
      }

      if (top == 0) {
        cout << "-1" << endl;
      } else {
        cout << sideward << " " << sideward << " " << top << " " << bottom << endl;
      }
    }

    t--;
  }

  return 0;
}
