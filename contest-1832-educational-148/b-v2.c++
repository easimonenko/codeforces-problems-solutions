#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

long long find_max_sum(vector<int> & a, vector<long long> & sums, int k, int l, int r) {
  if (k == 0) {
    return sums[r + 1] - sums[l];
  } else {
    return max(find_max_sum(a, sums, k - 1, l + 2, r), find_max_sum(a, sums, k - 1, l, r - 1));
  }
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    vector<long long> sums(n + 1);
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
      sums[i + 1] = sums[i] + a[i];
    }

    cout << find_max_sum(a, sums, k, 0, n - 1) << endl;

    t--;
  }
  
  return 0;
}
