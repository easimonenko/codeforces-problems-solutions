#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<vector<int>> tree(n, vector<int>());
  for (int k = 0; k < n - 1; k++) {
    int u, v;
    cin >> u >> v;
    tree[u - 1].push_back(v - 1);
    tree[v - 1].push_back(u - 1);
  }

  queue<int> q;
  q.push(0);
  vector<int> used(n, -1);
  used[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < tree[u].size(); j++) {
      int v = tree[u][j];
      if (used[v] == -1) {
        used[v] = used[u] + 1;
        q.push(v);
      }
    }
  }

  for (int u = 0; u < n; u++) {
    if (tree[u].size() != 1) {
      continue;
    }
    bool found = true;
    int level = 0;
    vector<vector<int>> levels(n);
    for (int v = 0; v < n; v++) {
      levels[abs(used[u] - used[v])].push_back(v);
    }
    for (int l = 1; l < levels.size(); l++) {
      for (int k = 1; k < levels[l].size(); k++) {
        if (tree[levels[l][k]].size() != tree[levels[l][k - 1]].size()) {
          found = false;
          break;
        }
      }
      if (!found) {
        break;
      }
    }
    if (found) {
      cout << u + 1 << endl;
      return 0;
    }
  }

  cout << "-1" << endl;

  return 0;
}
