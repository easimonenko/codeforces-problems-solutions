#include <iostream>

using namespace std;

int main() {
  int cnt1, cnt2, cnt3, cnt4;
  cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;

  if (cnt1 == cnt4 && (cnt3 <= cnt1 || cnt1 >= 1)) {
    cout << "1" << endl;
  } else {
    cout << "0" << endl;
  }

  return 0;
}
