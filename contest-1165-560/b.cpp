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

  int answer = 1;
  sort(begin(a), end(a));
  for (int i = 0; i < n; i++) {
    if (a[i] >= answer) {
      answer++;
    }
  }
  answer -= 1;
  cout << answer << endl;

  return 0;
}
