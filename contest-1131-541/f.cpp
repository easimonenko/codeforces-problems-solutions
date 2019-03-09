#include <iostream>
#include <vector>

using namespace std;

enum color {
  white, grey, black
};

void dfs(vector<vector<int> > & g, vector<int> & s, int u) {
  static vector<color> color(g.size());
  s.push_back(u);
  color[u] = grey;
  for (unsigned int k = 0; k < g[u].size(); k++) {
    if (color[g[u][k]] == white) {
      dfs(g, s, g[u][k]);
    }
  }
  color[u] = black;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> > g(n, vector<int>());
  for (int k = 0; k < n - 1; k++) {
    int u, v;
    cin >> u >> v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
  }

  vector<int> s;
  int u = 0;
  for (; u < n-1; u++) {
    if (g[u].size() == 1) {
      break;
    }
  }
  dfs(g, s, u);

  cout << s[0] + 1;
  for (int i = 1; i < n; i++) {
    cout << ' ' << s[i] + 1;
  }
  cout << endl;

  return 0;
}
