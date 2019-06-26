#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int minimum, maximum;
    cin >> minimum;
    maximum = minimum;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      minimum = min(minimum, a);
      maximum = max(maximum, a);
    }

    int b = minimum + k;
    cout << (b + k >= maximum ? b : -1) << endl;

    t--;
  }
  return 0;
}
