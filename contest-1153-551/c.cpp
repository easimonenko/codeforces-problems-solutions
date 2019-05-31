#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string &s, int r) {
  bool result = true;
  stack<int> st;
  for (int i = 0; i < r; i++) {
    if (st.empty()) {
      if (s[i] == '(') {
        st.push('(');
      } else {
        result = false;
        break;
      }
    } else {
      if (s[i] == ')' && st.top() == '(') {
        st.pop();
      } else if (s[i] == '(') {
        st.push('(');
      } else {
        result = false;
        break;
      }
    }
  }

  if (!st.empty()) {
    result = false;
  }

  return result;
}

int main() {
  int len;
  cin >> len;
  string s;
  cin >> s;

  bool ok = true;
  if (len % 2 == 0) {
    for (int i = 0; i < len / 2; i++) {
      if (s[i] == '(' && s[len - 1 - i] == '?') {
        s[len - 1 - i] = ')';
      } else if (s[i] == '?' && s[len - 1 - i] == ')') {
        s[i] = '(';
      } else if (s[i] == '?' && s[len - 1 - i] == '?') {
        s[i] = '(';
        s[len - 1 - i] = ')';
      } else if (s[i] == '?' && s[len - 1 - i] == '(') {
        s[i] = ')';
      } else if (s[i] == ')' && s[len - 1 - i] == '?') {
        s[len - 1 - i] = '(';
      }
    }
    for (int r = 1; r < len - 1; r++) {
      if (check(s, r)) {
        ok = false;
      }
    }
    if (ok) {
      ok = check(s, len);
    }
  } else {
    ok = false;
  }

  cout << (ok ? s : ":(") << endl;

  return 0;
}
