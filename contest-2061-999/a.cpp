#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;
  while (t != 0) {
    int n;
    cin >> n;
    int e = 0, o = 0;
    for (size_t i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }

    int ans = 0;
    if (e > 0) {
      ans++;
      ans += o;
    } else {
      ans += o - 1;
    }

    cout << ans << endl;

    t--;
  }
  return 0;
}
