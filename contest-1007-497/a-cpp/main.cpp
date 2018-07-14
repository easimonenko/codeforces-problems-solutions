#include <iostream>

using namespace std;

bool vowel(char c) {
  switch (c) {
  case 'a':
  case 'o':
  case 'u':
  case 'i':
  case 'e':
    return true;
  default:
    return false;
  }
}

int main() {
  string s;
  cin >> s;

  bool ans = true;

  if (s.length() > 1) {
    for (unsigned int i = 0; i < s.length() - 1; i++) {
      if (!(vowel(s[i]) || s[i] == 'n')) {
	if (!vowel(s[i+1])) {
	  ans = false;
	  break;
	}
      }
    }

    if (ans) {
      unsigned int last = s.length() - 1;
      if (s[last] != 'n' && !vowel(s[last])) {
	ans = false;
      }
    }
  }
  else {
    if (!(vowel(s[0]) || s[0] == 'n')) {
      ans = false;
    }
  }
  
  cout << (ans ? "YES" : "NO") << endl;
  
  return 0;
}

