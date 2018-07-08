#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<int> s, d;
  int a;
  cin >> a;
  int ans = n - 1;
  s.insert(a);
  for (int i = 2; i < n; i++) {
    int a;
    cin >> a;
    if (s.find(a) != s.end()) {
      if (d.find(a) != d.end()) {
	ans -= s.size();
      }
      else {
	d.insert(a);
      }
    }
    else {
      ans += n - i;
      s.insert(a);
    }
  }

  cout << ans << endl;
  
  return 0;
}
