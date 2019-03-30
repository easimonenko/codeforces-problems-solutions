#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

vector<bool> sums(10000000 + 1);
vector<bool> bad_sums(10000000 + 1);

bool find_sum(vector<int> & a, int r, int idx, int sum) {
  if (idx == a.size()) {
    return false;
  } else {
    int new_sum = sum + a[idx];
    if (new_sum == r) {
      sums[new_sum] = true;
      return true;
    } else if (new_sum > r) {
      idx++;
      sums[new_sum] = true;
      return find_sum(a, r, idx, sum);
    } else {
      idx++;
      sums[new_sum] = true;
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
    sums[a[i]] = true;
    s += a[i];
  }
  int t;
  cin >> t;

  int ans = 0;

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  for (int i = 1; i < n; i++) {
    static int sum = a[0];
    sum += a[i];
    sums[sum] = true;
  }
  for (int i = n - 2; i >= 0; i--) {
    static int sum = a[n - 1];
    sum += a[i];
    sums[sum] = true;
  }

  int l = s / gcd(t, s);
  for (int k = 1; k <= l; k++) {
    long long tt = k * (long long)t;
    int r = tt % s;

    if (!bad_sums[r] && (r == 0LL || sums[r] || sums[s - r] || find_sum(a, max(r, s - r), 0, 0))) {
      ans = k;
      break;
    } else {
      bad_sums[r] = true;
      bad_sums[s - r] = true;
    }
  }

  cout << (long long)t * ans << endl;

  return 0;
}
