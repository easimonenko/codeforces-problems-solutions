#include <iostream>

using namespace std;

int l;

long long f() {
  if (l == 0) {
    return 0;
  }

  long long res = 0;
  string cmd;
  do {
    cin >> cmd;
    l--;
    if (cmd == "end") {
      break;
    } else if (cmd == "add") {
      res++;
    } else if (cmd == "for") {
      int n;
      cin >> n;
      long long nested = n * f();
      if (nested > 0xFFFFFFFF) {
        cout << "OVERFLOW!!!" << endl;
        exit(0);
      }
      res += nested;
    } else {
      exit(-1);
    }
  } while (l > 0 && res <= 0xFFFFFFFF);

  if (res > 0xFFFFFFFF) {
    cout << "OVERFLOW!!!" << endl;
    exit(0);
  }

  return res;
}

int main() {
  cin >> l;

  long long res = f();
  if (res > 0xFFFFFFFF) {
    cout << "OVERFLOW!!!" << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}
