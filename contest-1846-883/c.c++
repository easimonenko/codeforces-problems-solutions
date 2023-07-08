#include<algorithm>
#include <cstddef>
#include <cstdlib>
#include<iostream>
#include <utility>
#include<vector>

using namespace std;

void print_results(vector<pair<pair<int, long long>, int>>& r) {
  for (size_t i = 0; i < r.size(); i++) {
    cout << r[i].first.first << " " << r[i].first.second << " " << r[i].second << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<pair<pair<int, long long>, int>> results(n, make_pair(make_pair(0, 0), 0));
    for (int i = 0; i < n; i++) {
      results[i].second = i + 1;
      vector<int> t(m);
      for (int j = 0; j < m; j++) {
        cin >> t[j];
      }
      sort(t.begin(), t.end());

      long long sum_time = 0;
      for (int j = 0; j < m; j++) {
        long long penalty = sum_time + t[j];
        if (penalty <= (long long)h) {
          results[i].first.first++;
          results[i].first.second += penalty;
          sum_time = penalty;
        } else {
          break;
        }
      }
    }
    
    for (int i = 0; i < n; i++) {
      results[i].first.first = m - results[i].first.first;
    }
    #ifdef DEBUG
    print_results(results);
    #endif
    sort(results.begin(), results.end());
    #ifdef DEBUG
    print_results(results);
    #endif

    for (int i = 0; i < n; i++) {
      if (results[i].second == 1) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
  return 0;
}
