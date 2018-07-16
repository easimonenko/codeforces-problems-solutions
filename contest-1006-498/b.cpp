#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#undef DEBUG

void printv(vector<int> & v) {
#if defined(DEBUG)
  for_each(v.begin(), v.end(), [](auto elem) {
      cout << elem << ' ';
    });
  cout << endl;
#endif
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<pair<int,int> > p(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p[i] = make_pair(a, i);
  }

  stable_sort(p.begin(), p.end());
  vector<int> idx(k);
  for (int r = n - k; r < n; r++) {
    idx[r - (n - k)] = p[r].second;
  }
  sort(idx.begin(), idx.end());
  printv(idx);

  int s = 0;
  for (int r = n - k; r < n; r++) {
    s += p[r].first;
  }
  cout << s << endl;
  if (k == 1) {
    cout << n << endl;
  }
  else {
    int r = 0;
    cout << idx[r] + 1 << ' ';
    r++;
    for (; r < k; r++) {
      int d;
      if (r == k - 2) {
	d = idx[r] - idx[r-1] + idx[r+1] - idx[r] - 1;
      }
      else if (r == k - 1) {
	d = n - idx[r];
      }
      else {
	d = idx[r] - idx[r-1];
      }
      cout << d << ' ';
    }
    cout << endl;
  }
  
  return 0;
}
