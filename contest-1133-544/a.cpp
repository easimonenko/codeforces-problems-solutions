#include <iostream>

using namespace std;

int main() {
  int h1, m1;
  scanf("%d:%d", &h1, &m1);
  int h2, m2;
  scanf("%d:%d", &h2, &m2);

  int d = (m1 + m2) / 2 + (h2 - h1) * 60 / 2;
  int h = h1 + d / 60;
  int m = d % 60;
  cout << (h < 10 ? "0" : "") << h << ":" << (m < 10 ? "0" : "") << m << endl;
  return 0;
}
