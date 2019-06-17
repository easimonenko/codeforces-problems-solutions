#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  priority_queue<int> teams;
  for (int i = 0; i < n; i++) {
    static int first_idx = 0;
    if (i == n - 1) {
      /* while (a[i] - a[first_idx] > 5 && first_idx < i) {
        first_idx++;
      }*/
      teams.push(i - first_idx + 1);
    } else if (a[i] - a[first_idx] > 5) {
      teams.push(i - first_idx);
      first_idx = i;
    }
  }

  int answer = 0;
  while (!teams.empty() && k > 0) {
    answer += teams.top();
    teams.pop();
    k--;
  }
  cout << answer << endl;

  return 0;
}
