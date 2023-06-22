#include<algorithm>
#include<iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    for (int k = 0; k < m; k++) {
      int u, v;
      cin >> u >> v;
      deg[u-1]++;
      deg[v-1]++;
    }
    sort(deg.begin(), deg.end());
    int with_one = 0;
    int i = 0;
    while (deg[i] == 1) {
      with_one++;
      i++;
    }
    int x = n - 1 - with_one;
    int y = with_one / x;
    cout << x << " " << y << endl;
    t--;
  }
  return 0;
}
