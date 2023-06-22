#include<iostream>

using namespace std;

bool solve(int n, int m) {
  if (n == m) {
    return true;
  } else if (n % 3 == 0) {
    int p = n / 3;
    if (p == m || p * 2 == m ) {
      return true;
    } else {
      return solve(p, m) || solve(p * 2, m);
    }
  } else {
    return false;
  }
}

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    cout << (solve(n, m) ? "YES" : "NO") << endl;
    t--;
  }
  return 0;
}
