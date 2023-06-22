#include<iostream>
#include<vector>

using namespace std;

int solve(vector<vector<int>> &a, vector<vector<bool>> &u, int i, int j) {
  if (i < 0 || i >= a.size() || j < 0 || j >= a[0].size()) {
    return 0;
  }
  if (!u[i][j] && a[i][j] > 0) {
    u[i][j] = true;
    return a[i][j]
      + solve(a, u, i, j - 1)
      + solve(a, u, i, j + 1)
      + solve(a, u, i - 1, j)
      + solve(a, u, i + 1, j);
  }
  return 0;
}

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    int ans = 0;
    vector<vector<bool>> u(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = max(ans, solve(a, u, i, j));
      }
    }
    cout << ans << endl;
    t--;
  }
  return 0;
}
