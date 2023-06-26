#include<iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum_a += a;
    }
    for (int j = 0; j < m; j++) {
      int b;
      cin >> b;
      sum_b += b;
    }
    if (sum_a > sum_b) {
      cout << "Tsondu" << endl;
    } else if (sum_b > sum_a) {
      cout << "Tenzing" << endl;
    } else {
      cout << "Draw" << endl;
    }
    t--;
  }
  return 0;
}
