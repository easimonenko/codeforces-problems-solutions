#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#undef DEBUG

void printv(vector<long long> & v) {
#if defined(DEBUG)
  for_each(v.begin(), v.end(), [](auto elem) {
      cout << elem << ' ';
    });
  cout << endl;
#endif
}

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  vector<long long> s1(n);
  s1[0] = d[0];
  for (int i = 1; i < n; i++) {
    s1[i] = s1[i-1] + d[i];
  }
  printv(s1);

  vector<long long> s2(n);
  s2[n-1] = d[n-1];
  for (int i = n-2; i >= 0; i--) {
    s2[i] = s2[i+1] + d[i];
  }
  printv(s2);

  long long ans = 0;
  int l = 0, r = n - 1;
  while (l < r) {
    if (s1[l] == s2[r]) {
      ans = s1[l];
      l++; r--;
    }
    else if (s1[l] < s2[r]) {
      l++;
    }
    else {
      r--;
    }
  }
  cout << ans << endl;
  
  return 0;
}
