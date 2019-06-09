#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long answer = 0;
  int best_left_index = a.size();
  for (int r = k; r > 0; r--) {
    long long best_sum = r * a[best_left_index - 1];
    best_left_index--;
    long long s = best_sum;
    for (int i = best_left_index - 1; i >= r - 1; i--) {
      s = s + r * a[i];
      if (r != 1 && s > best_sum) {
        best_sum = s;
        best_left_index = i;
      }
    }
    if (r == 1) {
      answer += s;
    } else {
      answer += best_sum;
    }
  }

  cout << answer << endl;

  return 0;
}
