#include <iostream>
#include <vector>

using namespace std;

int maxv(vector<int> &v) {
  int ans = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (v[i] > ans) {
      ans = v[i];
    }
  }
  return ans;
}

int max_col(vector<vector<int> > &v, int k) {
  int ans = -1;

  for (int j = 0; j < v[0].size(); j++) {
    int maxc = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[i][j] > maxc) {
        maxc = v[i][j];
      }
    }
    if (v[k][j] == maxc) {
      ans = j;
      break;
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  k -= 1;

  vector<vector<int> > c(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }

  vector<int> s(n, 0);
  vector<vector<int> > r(n, vector<int>(m, 0));
  vector<vector<int> > d(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s[i] += c[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      r[i][j] = s[i] - c[i][j] + 10 - c[i][j];
      d[i][j] = s[i] - c[i][j];
    }
  }
  //cout << s[k] << " " << maxv(s) << endl;
  if (s[k] == maxv(s)) {
    cout << "YES 0" << endl;
  } else {
    int p = max_col(r, k);
    if (p != -1) {
      cout << "REV " << p + 1 << endl;
    } else {
      int p = max_col(d, k);
      if (p != -1) {
        cout << "DEL " << p + 1 << endl;
      } else {
        cout << "NOP 0" << endl;
      }
    }
  }
  return 0;
}
