#include <iostream>

using namespace std;

int solve(int k, int n, int a, int b) {
  if (k / b - (k % b == 0 ? 1 : 0) < n) {
    return -1;
  } else {
    int answer = k / a;
    if (k % a == 0) {
      answer--;
    }
    if (answer >= n) {
      return n;
    } else {
      int delta = k - answer * a;
      int powered = delta / b;
      if (delta % b == 0) {
        powered--;
      }
      if (answer + powered >= n) {
        return answer;
      } else {
        int c = n - (answer + powered);
        int d = c * b;

        return solve(k - (d + powered * b), n - powered - c, a, b);
      }
    }
  }
}

int main() {
  int q;
  cin >> q;
  while (q > 0) {
    int k, n, a, b;
    cin >> k >> n >> a >> b;
    cout << solve(k, n, a, b) << endl;

    q--;
  }

  return 0;
}
