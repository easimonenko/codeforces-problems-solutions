#include<iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k, x;
    cin >> n >> k >> x;
    if (x != 1) {
      cout << "YES" << endl;
      cout << n << endl;
      cout << "1";
      for (int i = 1; i < n; i++) {
        cout << " 1";
      }
      cout << endl;
    } else {
      if (k == 1) {
        cout << "NO" << endl;
      } else {
        if (n % 2 == 0) {
          int r = n / 2;
          cout << "YES" << endl;
          cout << r << endl;
          cout << "2";
          for (int i = 1; i < r; i++) {
            cout << " 2";
          }
          cout << endl;
        } else {
          if (k == 2) {
            cout << "NO" << endl;
          } else {
            int r = n / 2 - 1;
            cout << "YES" << endl;
            cout << r + 1 << endl;
            if (r > 0) {
              cout << "2";
              for (int i = 1; i < r; i++) {
                cout << " 2";
              }
              cout << " 3" << endl;  
            } else {
              cout << "3" << endl;  
            }
          }
        }
      }
    }
  }
  return 0;
}
