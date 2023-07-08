#include<iostream>
#include<vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    double n, d, h;
    cin >> n >> d >> h;
    double p = d * h / 2.0;
    double s = p;
    double y_prev;
    cin >> y_prev;
    for (int i = 1; i < n; i++) {
      double y;
      cin >> y;
      s = s + p;
      double delta = y_prev + h - y;
      if (delta > 0) {
        s = s - delta * d * (delta / h) / 2.0;
      }
      y_prev = y;
    }
    //cout << s << endl;
    printf("%f\n", s);
  }
  return 0;
}
