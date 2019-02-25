#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool check_primary(long long n) {
  bool res = true;

  long long middle = sqrt(n);

  if (n <= 1) {
    res = false;
  } else if (n != 2LL && n % 2LL == 0) {
    res = false;
  } else {
    for (long long k = 3; k <= middle; k += 2LL) {
      if (n % k == 0) {
        res = false;
        break;
      }
    }
  }

  return res;
}

long long min_primary_div(long long n) {
  static bool nead_calc = true;
  static vector<long long> primary_divs;

  long long ans = 0LL;

  if (nead_calc) {
    primary_divs.push_back(2LL);
    for (long long d = 3LL; d <= n; d++) {
      if (check_primary(d)) {
        primary_divs.push_back(d);
      }
    }
    nead_calc = false;
  } else {
    for (vector<long long>::size_type i = 0; i < primary_divs.size(); i++) {
      if (n % primary_divs[i] == 0) {
        ans = primary_divs[i];
        break;
      }
    }
  }

  return ans;
}

int main() {
  long long n;
  cin >> n;

  int res = 0;

  while (n != 0 && n != 1) {
    n -= min_primary_div(n);
    res += 1;
  }

  cout << res << endl;

  return 0;
}
