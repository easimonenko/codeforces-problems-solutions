#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  if (n % 2 == 0) {
    cout << (1 << (n / 2)) << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}
