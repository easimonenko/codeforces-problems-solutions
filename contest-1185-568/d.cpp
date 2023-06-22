// TODO: incomplete solution.

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  if (n <= 3) {
    cout << "1" << endl;
  }

  int counter = 0;
  int idx = -1;

  if (counter >= 2) {
    cout << "-1" << endl;
  } else {
    cout << idx << endl;
  }

  return 0;
}
