#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> open_seq(n);
  int left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    cin >> open_seq[i];
    if (open_seq[i] == 0) {
      left++;
    } else {
      right++;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (open_seq[i] == 0) {
      left--;
    } else {
      right--;
    }
    ans++;
    if (left == 0 || right == 0) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
