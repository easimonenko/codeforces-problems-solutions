#include <algorithm>
#include <iostream>
#include <queue>
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
  priority_queue<int> q;
  q.push(t[0]);
  for (int i = 1; i < n; i++) {
    int mc = ms;
    if (t[i] + ms <= m) {
      cout << " 0";
    } else {
      int answer = 0;
      int k = i - 1;
      auto qt = q;
      while (mc > m - t[i]) {
        mc -= qt.top();
        qt.pop();
        answer++;
        k--;
      }
      cout << " " << answer;
    }
    ms += t[i];
    q.push(t[i]);
  }
  cout << endl;

  return 0;
}
