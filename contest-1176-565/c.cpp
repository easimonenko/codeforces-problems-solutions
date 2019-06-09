#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> indexes(42 + 1, vector<int>());
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    indexes[a].push_back(i);
  }
  vector<int> last_used(42 + 1, -1);
  int p[] = {4, 8, 15, 16, 23, 42};

  int found_counter = 0;
  for (int r = 0; r < indexes[p[0]].size(); r++) {
    last_used[p[0]] = r;
    int found = 1;
    for (int k = 1; k < 6; k++) {
      for (int l = last_used[p[k]] + 1; l < indexes[p[k]].size(); l++) {
        last_used[p[k]] = l;
        if (indexes[p[k]][l] > indexes[p[k - 1]][last_used[p[k - 1]]]) {
          found++;
          break;
        }
      }
    }
    if (found == 6) {
      found_counter++;
    }
  }

  cout << n - 6 * found_counter << endl;

  return 0;
}
