#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    int n;
    cin >> n;
    int c[] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a % 3]++;
    }

    cout << c[0] + min(c[1], c[2]) + abs(c[2] - c[1]) / 3 << endl;
    t--;
  }
  return 0;
}
