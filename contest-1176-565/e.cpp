#include <iostream>
#include <vector>

using namespace std;

void normalize(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    v[i]++;
  }
}

void printv(vector<int> &v) {
  if (v.size() != 0) {
    cout << v[0];
    for (int i = 1; i < v.size(); i++) {
      cout << " " << v[i];
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>());
    for (int k = 0; k < m; k++) {
      int u, v;
      cin >> u >> v;
      graph[u - 1].push_back(v - 1);
      graph[v - 1].push_back(u - 1);
    }
    vector<int> answer, other;
    vector<bool> used(n, false);
    for (int u = 0; u < n; u++) {
      if (!used[u]) {
        answer.push_back(u);
        used[u] = true;
        for (int v : graph[u]) {
          if (!used[v]) {
            other.push_back(v);
            used[v] = true;
          }
        }
      }
    }
    if (answer.size() <= n / 2) {
      cout << answer.size() << endl;
      normalize(answer);
      printv(answer);
    } else {
      cout << other.size() << endl;
      normalize(other);
      printv(other);
    }
    t--;
  }

  return 0;
}
