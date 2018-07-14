#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> divs(int x) {
  vector<int> d;
  for (int k = 1; k <= sqrt(x); k++) {
    if (x % k == 0) {
      d.push_back(k);
    }
  }
  return d;
}

int main() {
  int t;
  cin >> t;

  vector<long long> s(100000 + 1);
  s[0] = 0;
  for (int i = 1; i < s.size(); i++) {
    s[i] = s[i-1] + i;
  }

  vector<long long> ss(s.size() + 1);
  ss[0] = s[0];
  for (int i = 1; i < ss.size(); i++) {
    ss[i] = ss[i-1] + s[i];
  }

  while (t > 0) {
    t--;
    int a, b, c;
    cin >> a >> b >> c;
    long long ans = 0;
    vector<int> da = divs(a), db = divs(b), dc = divs(c);
    for (int i = 0; i < da.size(); i++) {
      for (auto b_it = lower_bound(db.begin(), db.end(), da[i]); b_it != db.end(); b_it++) {
	auto c_it = lower_bound(dc.begin(), dc.end(), *b_it);
	if (c_it != dc.end()) {
	  ans = ans + (dc.end() - c_it) + 1;
	}
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
