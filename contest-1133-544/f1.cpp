#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> tree(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    tree[u - 1].push_back(v - 1);
    tree[v - 1].push_back(u - 1);
  }

  int start = 0, max_degree = tree[0].size();
  for (int u = 1; u < n; u++) {
    if (tree[u].size() > max_degree) {
      start = u;
      max_degree = tree[u].size();
    }
  }

  vector<pair<int, int>> answer;

  queue<int> q;
  q.push(start);
  vector<bool> used(n, false);
  used[start] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int k = 0; k < tree[u].size(); k++) {
      int v = tree[u][k];
      if (!used[v]) {
        q.push(v);
        used[v] = true;
        answer.push_back(make_pair(u, v));
      }
    }
  }

  for (auto edge : answer) {
    cout << edge.first + 1 << " " << edge.second + 1 << endl;
  }

  return 0;
}
