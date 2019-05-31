#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int answer = 0;
  int d;
  cin >> d;
  if (d == 1) {
    answer++;
  }
  for (int i = 2; i <= n; i++) {
    int a;
    cin >> a;
    d = max(a, d);
    if (i == d) {
      answer++;
    }
  }

  cout << answer << endl;

  return 0;
}
