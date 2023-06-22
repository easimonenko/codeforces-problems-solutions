#include <cstddef>
#include<iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cin >> t;
  string c = "codeforces";
  while (t > 0) {
    string s;
    cin >> s;
    int ans = 0;
    for (size_t i = 0; i < 10; i++) {
      if (s[i] != c[i]) {
        ans += 1;
      }
    }
    cout << ans << endl;
    t--;
  }
  return 0;
}
