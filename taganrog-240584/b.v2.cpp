#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

vector<bool> sums(10000000 + 1);

bool find_sum(vector<int> & a, int r, int idx, int sum) {
  if (idx == a.size()) {
    return false;
  } else if (r < 0) {
    return false;
  } else {
    int new_sum = sum + a[idx];
    if (new_sum > r) {
      sums[new_sum] = true;
      return false;
    } else if (new_sum == r) {
      sums[new_sum] = true;
      return true;
    } else {
      idx++;
      sums[new_sum] = true;
      return find_sum(a, r - new_sum, idx, 0)
        || find_sum(a, r - sum, idx, 0);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sums[a[i]] = true;
    s += a[i];
  }
  int t;
  cin >> t;

  int ans = 0;

  sort(a.begin(), a.end());
  int l = s / gcd(t, s);
  for (int k = 1; k <= l; k++) {
    long long tt = k * (long long)t;
    long long r = tt % s;

    //r = r / gcd(tt, s);

    if (r == 0LL || sums[r] || find_sum(a, r, 0, 0)) {
      ans = k;
      break;
    }
  }

  cout << (long long)t * ans << endl;

  return 0;
}
