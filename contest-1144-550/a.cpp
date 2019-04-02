#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  while (n > 0) {
    cin >> s;
    sort(s.begin(), s.end());
    bool ans = true;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] - s[i - 1] != 1) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "Yes" : "No") << endl;
    n--;
  }
  return 0;
}
