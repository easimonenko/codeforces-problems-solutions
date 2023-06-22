#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

long long find_max_sum(vector<int> & a, vector<long long> & sums, int k) {
  long long sum = 0;
  int n = a.size();
  for (int m = 0; m <= k; m++) {
    sum = max(sum, sums[n - (k - m)] - sums[2 * m]);
  }
  
  return sum;
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

    cout << find_max_sum(a, sums, k) << endl;

    t--;
  }
  
  return 0;
}
