#include<iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int xa, ya;
    cin >> xa >> ya;
    int xb, yb;
    cin >> xb >> yb;
    xb -= xa; yb -= ya;
    int xc, yc;
    cin >> xc >> yc;
    xc -= xa; yc -= ya;
    xa = 0; ya = 0;
    int dx = 0, dy = 0;
    if ((long long)xb * (long long)xc >= 0LL) {
      dx = min(abs(xb), abs(xc));
    }
    if ((long long)yb * (long long)yc >= 0LL) {
      dy = min(abs(yb), abs(yc));
    }
    cout << dx + dy + 1 << endl;
  }
  return 0;
}
