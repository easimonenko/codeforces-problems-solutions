#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  string s;
  cin >> s;

  int answer = 0;
  reverse(begin(s), end(s));
  for (int i = 0; i < x; i++) {
    if ((i == y && s[i] != '1') || (i != y && s[i] != '0')) {
      answer++;
    }
  }
  cout << answer << endl;

  return 0;
}
