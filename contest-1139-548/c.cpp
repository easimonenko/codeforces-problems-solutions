#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#undef DEBUG

enum color { white, gray, black };

int bfs(vector<vector<int>> &tree, vector<color> &colors, int u) {
  int res = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (colors[v] == white) {
      colors[v] = black;
      res++;
      for (int i = 0; i < tree[v].size(); i++) {
        if (colors[tree[v][i]] == white) {
          q.push(tree[v][i]);
        }
      }
    }
  }

  return res;
}

int pow(int a, int n, int m) {
  long long res = 1;
  for (int j = 0; j < n; j++) {
    res = res * a;
    res = res % m;
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    if (c == 0) {
      tree[u - 1].push_back(v - 1);
      tree[v - 1].push_back(u - 1);
    }
  }

  const int MOD = 1e9 + 7;

  int ans = pow(n, k, MOD);

  vector<color> colors(n);
  for (int i = 0; i < n; i++) {
    if (colors[i] == white) {
      int p = bfs(tree, colors, i);
#ifdef DEBUG
      cout << p << endl;
#endif
      if (p > 0) {
        ans -= pow(p, k, MOD);
        ans += MOD;
        ans %= MOD;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
