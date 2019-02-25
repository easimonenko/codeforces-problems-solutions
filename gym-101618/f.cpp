#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    static int k = 0;
    if (k == 0) {
      k = 1;
    } else {
      if (s[i] != s[i - 1]) {
        k = 1;
      } else {
        k += 1;
        if (k == 3) {
          s[i] = '#';
          k = 1;
        }
      }
    }
  }

  cout << s << endl;

  return 0;
}
