#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  vector<bool> primes(1000000 + 1, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      for (int j = i * 2; j < primes.size(); j += i) {
        primes[j] = false;
      }
    }
  }

  while (t > 0) {
    int n;
    cin >> n;
    vector<int> counts(1000000 + 1, 0);
    set<int> divs;
    int min_primary_divisor = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      divs.insert(a);
      for (int k = 0; k < primes.size(); k++) {
        if (primes[k]) {
          int counter = 0;
          int r = a;
          while (r % k == 0) {
            r /= k;
            counter++;
          }
          if (counter > 0 && min_primary_divisor == 0) {
            min_primary_divisor = k;
          }
          if (counter > counts[k]) {
            counts[k] = counter;
          }
        }
      }
    }

    long long answer = 1;
    for (int k = 0; k < counts.size(); k++) {
      while (counts[k] > 0) {
        answer = answer * k;
        counts[k]--;
      }
    }
    int m = *(divs.begin());
    for (auto it = ++divs.begin(); it != divs.end(); it++) {
      m = max(m, *it);
    }
    if (answer == m) {
      answer = answer * min_primary_divisor;
    }
    int count_divs = 0;
    long long q = (long long)(sqrt(answer));
    for (long long d = 2; d <= q; d++) {
      if (answer % d == 0) {
        count_divs += 2;
      }
    }
    if ((answer % q == 0) && answer == q * q) {
      count_divs--;
    }
    if (count_divs == divs.size()) {
      cout << answer << endl;
    } else {
      cout << "-1" << endl;
    }
    t--;
  }
  return 0;
}
