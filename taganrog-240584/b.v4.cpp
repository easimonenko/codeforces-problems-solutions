#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

vector<int> sums(10000000 + 1);

bool find_sum(vector<int> & a, int r, int idx, int sum) {
  if (idx == a.size()) {
    return false;
  } else {
    int new_sum = sum + a[idx];
    if (new_sum > r) {
      sums[new_sum] += 1;
      return false;
    } else if (new_sum == r) {
      sums[new_sum] += 1;
      return true;
    } else if ((r - a[idx] != a[idx] && sums[r - a[idx]] > 0)
               || (r - a[idx] == a[idx] && sums[r - a[idx]] > 1)) {
      return true;
    } else {
      idx++;
      sums[new_sum] += 1;
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
    sums[a[i]] = 1;
    s += a[i];
  }
  int t;
  cin >> t;

  int ans = 0;

  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    static int sum = a[0];
    sum += a[i];
    sums[sum] += 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    static int sum = a[n - 1];
    sum += a[i];
    sums[sum] += 1;
  }

  int l = s / gcd(t, s);
  for (int k = 1; k <= l; k++) {
    long long tt = k * (long long)t;
    long long r = tt % s;

    if (r == 0LL || sums[r] > 0 || find_sum(a, r, 0, 0)) {
      ans = k;
      break;
    }
  }

  cout << (long long)t * ans << endl;

  return 0;
}
