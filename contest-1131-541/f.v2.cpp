#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &par, int k) {
  if (k == par[k]) {
    return k;
  }
  return par[k] = find(par, par[k]);
}

void unite(vector<vector<int>> &kittens, vector<int> &par, int x, int y) {
  int a = find(par, x);
  int b = find(par, y);
  if (kittens[b].size() > kittens[a].size()) {
    swap(a, b);
  }
  for (int k : kittens[b]) {
    kittens[a].push_back(k);
  }
  par[b] = a;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> kittens(n);
  vector<int> par(n);
  for (size_t i = 0; i < n; i++) {
    par[i] = i;
    kittens[i].push_back(i);
  }

  for (size_t i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    unite(kittens, par, x - 1, y - 1);
  }

  for (int k : kittens[find(par, 0)]) {
    cout << k + 1 << ' ';
  }
  cout << endl;

  return 0;
}
