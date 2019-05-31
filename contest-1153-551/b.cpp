#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, h;
  cin >> n >> m >> h;
  vector<int> front_view(m);
  for (int j = 0; j < m; j++) {
    cin >> front_view[j];
  }
  vector<int> left_view(n);
  for (int i = 0; i < n; i++) {
    cin >> left_view[i];
  }
  vector<vector<int>> heights(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bool h;
      cin >> h;
      if (h) {
        heights[i][j] = min(front_view[j], left_view[i]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << heights[i][0];
    for (int j = 1; j < m; j++) {
      cout << ' ' << heights[i][j];
    }
    cout << endl;
  }

  return 0;
}
