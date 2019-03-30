#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

vector<set<int> > sums(10000000 + 1);

bool find_sum(vector<int> & a, int r, int idx, int sum) {
  if (idx == a.size()) {
    return false;
  } else {
    int new_sum = sum + a[idx];
    if (new_sum > r) {
      sums[new_sum].insert(idx);
      return false;
    } else if (new_sum == r) {
      sums[new_sum].insert(idx);
      return true;
    } else {
      if (!sums[r - a[idx]].empty() && *(sums[r - a[idx]].lower_bound(idx)) < idx) {
        sums[r].insert(idx);
        return true;
      }
      idx++;
      sums[new_sum].insert(idx);
      return find_sum(a, r, idx, new_sum)
        || find_sum(a, r, idx, sum);
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
    s += a[i];
    sums[a[i]] = set<int>();
  }

  int t;
  cin >> t;

  int ans = 0;

  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    sums[a[i]].insert(i);
  }
  int l = s / gcd(t, s);
  for (int k = 1; k <= l; k++) {
    long long tt = k * (long long)t;
    long long r = tt % s;

    if (r == 0LL || !sums[r].empty() || find_sum(a, r, 0, 0)) {
      ans = k;
      break;
    }
  }

  cout << (long long)t * ans << endl;

  return 0;
}
