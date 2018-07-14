#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  
  int c = 0;
  for (int i = 0; i < min(s.size(), t.size()); i++) {
    if (s[i] == t[i]) {
      c++;
    }
    else {
      break;
    }
  }

  cout << (s.size() + t.size() - 2 * c) << endl;
  
  return 0;
}
