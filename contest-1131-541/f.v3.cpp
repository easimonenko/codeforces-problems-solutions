#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &par, vector<int> &dist, int k) {
  if (k == par[k]) {
    return k;
  }
  int r = find(par, dist, par[k]);
  dist[k] += dist[par[k]];
  return par[k] = r;
}

void unite(vector<int> &par, vector<int> &sz, vector<int> &dist, int x, int y) {
  int a = find(par, dist, x);
  int b = find(par, dist, y);
  if (sz[b] > sz[a]) {
    swap(a, b);
  }
  par[b] = a;
  dist[b] = sz[a];
  sz[a] += sz[b];
}

int main() {
  int n;
  cin >> n;

  vector<int> ans(n);
  vector<int> sz(n, 1), dist(n, 0), par(n);
  for (size_t i = 0; i < n; i++) {
    par[i] = i;
  }

  for (size_t i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    unite(par, sz, dist, x - 1, y - 1);
  }
  for (size_t i = 0; i < n; i++) {
    find(par, dist, i);
  }
  for (size_t i = 0; i < n; i++) {
    ans[dist[i]] = i;
  }

  cout << ans[0] + 1;
  for (size_t i = 1; i < n; i++) {
    cout << ' ' << ans[i] + 1;
  }
  cout << endl;

  return 0;
}
