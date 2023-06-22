#include<iostream>
#include<vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    int ans = 0;
    int curr_len = 0;
    for (size_t i = 0; i < n; i++) {
      int v;
      cin >> v;
      if (v == 1) {
        curr_len = 0;
      } else {
        curr_len += 1;
        if (curr_len > ans) {
          ans = curr_len;
        }
      }
    }
    cout << ans << endl;
    t--;
  }
  return 0;
}
