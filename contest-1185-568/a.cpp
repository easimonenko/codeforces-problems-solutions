#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> coords(3);
  cin >> coords[0];
  cin >> coords[1];
  cin >> coords[2];
  int d;
  cin >> d;

  sort(begin(coords), end(coords));

  int d1 = coords[1] - coords[0] < d ? d - (coords[1] - coords[0]) : 0;
  int d2 = coords[2] - coords[1] < d ? d - (coords[2] - coords[1]) : 0;
  cout << (d1 + d2) << endl;

  return 0;
}
