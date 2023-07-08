#include<iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      if (a > b) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
