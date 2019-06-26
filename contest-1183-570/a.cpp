#include <iostream>

using namespace std;

int sum_of_digits(int a) {
  int res = 0;
  while (a > 0) {
    res += a % 10;
    a /= 10;
  }

  return res;
}

int main() {
  int a;
  cin >> a;

  int n = a;
  while (sum_of_digits(n) % 4 != 0) {
    n++;
  }
  cout << n << endl;

  return 0;
}
