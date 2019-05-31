#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    int n;
    cin >> n;
    long long lesser, greater;
    set<long long> a;
    long long ai;
    cin >> ai;
    lesser = greater = ai;
    a.insert(ai);
    for (int i = 1; i < n; i++) {
      cin >> ai;
      a.insert(ai);
      lesser = min(lesser, ai);
      greater = max(greater, ai);
    }

    long long answer = lesser * greater;
    set<long long> divs;
    for (int k = 2; k <= (long long)(sqrt(answer)); k++) {
      if (answer % k == 0) {
        divs.insert(k);
        divs.insert(answer / k);
      }
    }

    if (a == divs) {
      cout << answer << endl;
    } else {
      cout << "-1" << endl;
    }

    t--;
  }
  return 0;
}
