#include<iostream>
#include<vector>
 
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, x;
    cin >> n >> x;
    int res = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      if (((x ^ a[i]) | (x & a[i])) == x) {
        res |= a[i];
      } else {
        break;
      }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
      if (((x ^ b[i]) | (x & b[i])) == x) {
        res |= b[i];
      } else {
        break;
      }
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
      if (((x ^ c[i]) | (x & c[i])) == x) {
        res |= c[i];
      } else {
        break;
      }
    }
    
    if (res == x) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    
    t--;
  }
  return 0;
}
