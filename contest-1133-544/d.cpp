#include <iostream>
#include <map>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  int answer = 0;
  map<pair<int, int>, int> d;
  int nulls = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      if (b[i] == 0) {
        nulls++;
      }
      continue;
    }
    int g = gcd(a[i], b[i]);
    d[make_pair(-b[i] / g, a[i] / g)]++;
  }
  for (auto p : d) {
    answer = max(answer, p.second);
  }
  cout << answer + nulls << endl;

  return 0;
}
