#include <iostream>

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q > 0) {
    long long n;
    int a, b;
    cin >> n >> a >> b;

    cout << min((n / 2) * b + (n % 2) * a, n * a) << endl;

    q--;
  }

  return 0;
}
