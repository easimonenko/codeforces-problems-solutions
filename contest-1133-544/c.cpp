#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));

  int answer = 1;
  for (int i = 1; i < n; i++) {
    static int first_idx = 0;
    if (a[i] - a[first_idx] > 5) {
      while (a[i] - a[first_idx] > 5 && first_idx < i) {
        first_idx++;
      }
    } else {
      answer = max(answer, i - first_idx + 1);
    }
  }
  cout << answer << endl;

  return 0;
}
