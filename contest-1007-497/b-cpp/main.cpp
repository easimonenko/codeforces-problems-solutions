#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  bool ans = true;

  int wp, hp;
  cin >> wp >> hp;
  if (hp < wp) {
    swap(hp, wp);
  }
  for (int i = 1; i < n; i++) {
    int wn, hn;
    cin >> wn >> hn;
    if (hp >= max(wn, hn)) {
      hp = max(wn, hn);
    }
    else if (hp >= min(wn, hn)) {
      hp = min(wn, hn);
    }
    else {
      ans = false;
      break;
    }
  }
  
  cout << (ans ? "YES" : "NO") << endl;
  
  return 0;
}
