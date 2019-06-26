#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  int answer = 0;
  int ms = t[0];
  cout << "0";
  for (int i = 1; i < n; i++) {
    int mc = ms;
    if (t[i] + ms <= m) {
      cout << " 0";
    } else {
      vector<int> tc(t.begin(), t.begin() + i);
      sort(begin(tc), end(tc));
      int answer = 0;
      int k = i - 1;
      while (mc > m - t[i]) {
        mc -= tc[k];
        answer++;
        k--;
      }
      cout << " " << answer;
    }
    ms += t[i];
  }
  cout << endl;

  return 0;
}
