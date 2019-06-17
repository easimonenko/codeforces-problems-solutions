#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c(k, 0);
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    c[d % k]++;
  }

  int answer = 0;
  for (int j = 0; j <= k / 2; j++) {
    if (j == (k - j) % k) {
      answer += c[j] / 2;
    } else {
      answer += min(c[j], c[k - j]);
    }
  }
  cout << answer * 2 << endl;

  return 0;
}
