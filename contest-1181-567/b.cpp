#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string sum(string l, size_t idx) {
  string res = "";
  size_t w = l.length();
  size_t w1 = idx;
  size_t w2 = w - idx + 1;


  return res;
}

int main() {
  size_t w;
  cin >> w;
  string l;
  cin >> l;

  vector<string> sums;
  if (w % 2 == 0) {
    auto idx = w / 2;
    while (idx < w && l[idx] == '0') {
      idx++;
    }
    if (idx == w) {
      idx = w / 2 - 1;
      while (idx >= 0 && l[idx] == '0') {
        idx--;
      }
      if (idx == -1) {
        return -1;
      }
    }
    cout << sum(l, idx) << endl;
  }

  return 0;
}
