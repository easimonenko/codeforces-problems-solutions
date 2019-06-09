#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;
  while (q > 0) {
    long long n;
    cin >> n;
    long long answer = 0;
    while (n % 5 == 0) {
      n /= 5LL;
      answer += 3LL;
    }
    while (n % 3 == 0) {
      n /= 3LL;
      answer += 2LL;
    }
    while (n % 2 == 0) {
      n >>= 1;
      answer++;
    }
    if (n == 1) {
      cout << answer << endl;
    } else {
      cout << "-1" << endl;
    }
    q--;
  }
  return 0;
}
