#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

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
    int l = 0, r = n - 1;
    while (k > 0) {
      if (a[l] + a[l + 1] <= a[r]) {
        l += 2;
      } else {
        r--;
      }
      k--;
    }
    
    long long sum = 0;
    for (int i = l; i <= r; i++) {
      sum = sum + a[i];
    }
    cout << sum << endl;

    t--;
  }
  
  return 0;
}
