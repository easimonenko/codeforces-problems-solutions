#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printv(vector<int> & v) {
  cout << v[0];
  for_each(v.begin() + 1, v.end(), [](auto elem) {
      cout << ' ' << elem;
  });
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = 0;
  
  vector<int> dp(n);
  set<int> r;
  dp[n - 1] = 1;
  r.insert(a[n - 1]);
  for (int i = n - 2; i >= 0; i--) {
    if (r.find(a[i]) != r.end()) {
      dp[i] = dp[i + 1];
    }
    else {
      dp[i] = dp[i + 1] + 1;
      r.insert(a[i]);
    }
  }
  //printv(dp);
  
  set<int> l;
  for (int i = 0; i < n - 1; i++) {
    if (l.find(a[i]) == l.end()) {
      ans += dp[i + 1];
      l.insert(a[i]);
    }
  }
  
  cout << ans << endl;
  
  return 0;
}

