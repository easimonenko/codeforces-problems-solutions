#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    string s, t;
    cin >> s >> t;
    s.push_back('*');
    t.push_back('*');
    vector<pair<char, int>> sc;
    char ch = s[0];
    int ct = 1;
    for (int i = 1; i < s.length(); i++) {
      if (i + 1 == s.length()) {
        sc.push_back(make_pair(ch, ct));
      } else if (s[i] != ch) {
        sc.push_back(make_pair(ch, ct));
        ch = s[i];
        ct = 1;
      } else {
        ct++;
      }
    }
    vector<pair<char, int>> tc;
    ch = t[0];
    ct = 1;
    for (int j = 1; j < t.length(); j++) {
      if (j + 1 == t.length()) {
        tc.push_back(make_pair(ch, ct));
      } else if (t[j] != ch) {
        tc.push_back(make_pair(ch, ct));
        ch = t[j];
        ct = 1;
      } else {
        ct++;
      }
    }
    bool answer = true;
    if (sc.size() == tc.size()) {
      for (int k = 0; k < sc.size(); k++) {
        if (sc[k].first != tc[k].first || sc[k].second > tc[k].second) {
          answer = false;
          break;
        }
      }
    } else {
      answer = false;
    }

    cout << (answer ? "YES" : "NO") << endl;
    n--;
  }
  return 0;
}
