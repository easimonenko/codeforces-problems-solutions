#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    long long n, k;
    cin >> n >> k;
    long long answer = 0;
    while (n > 0) {
      if (n % k == 0) {
        answer++;
        n /= k;
      } else {
        long long r = n / k * k;
        answer += n - r;
        n = r;
      }
    }
    cout << answer << endl;
    t--;
  }

  return 0;
}
