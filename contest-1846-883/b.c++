#include<iostream>
#include<vector>

using namespace std;

bool check(vector<string> &p, char c) {
  return ((p[0][0] & p[0][1] & p[0][2]) == c)
    || ((p[1][0] & p[1][1] & p[1][2]) == c)
    || ((p[2][0] & p[2][1] & p[2][2]) == c)
    || ((p[0][0] & p[1][0] & p[2][0]) == c)
    || ((p[0][1] & p[1][1] & p[2][1]) == c)
    || ((p[0][2] & p[1][2] & p[2][2]) == c)
    || ((p[0][0] & p[1][1] & p[2][2]) == c)
    || ((p[0][2] & p[1][1] & p[2][0]) == c);
}

int main() {
  int t;
  cin>> t;
  while (t-- > 0) {
    vector<string> p(3);
    cin >> p[0];
    cin >> p[1];
    cin >> p[2];
    if (check(p, 'X')) {
      cout << "X" << endl;
    } else if (check(p, 'O')) {
      cout << "O" << endl;
    } else if (check(p, '+')) {
      cout << "+" << endl;
    } else {
      cout << "DRAW" << endl;
    }
  }
  return 0;
}
