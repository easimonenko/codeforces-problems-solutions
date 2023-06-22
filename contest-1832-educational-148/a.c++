#include<iostream>
#include<vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    string s;
    cin >> s;
    bool ans = false;
    for (int i = 0; i < s.length() / 2 - 1; i++) {
      if (s[i] != s[i + 1]) {
        ans = true;
        break;
      }
    }
    cout << (ans ? "YES" : "NO") << endl;
    
    t--;
  }
  
  return 0;
}
