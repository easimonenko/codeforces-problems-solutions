#include <iostream>
#include <vector>

using namespace std;

#undef DEBUG

int dp(vector<int> x) {
  int res = 1;
  for (int i = 0; i < x.size(); i++) {
    res *= x[i];
  }
  return res;
}

vector<int> convert(int x) {
  vector<int> res;
  while (x != 0) {
    res.push_back(x % 10);
    x /= 10;
  }
  return res;
}

void dec(vector<int> &d, int idx) {
  if (idx >= d.size()) {
    return;
  }
  if (d[idx] != 0) {
    d[idx] -= 1;
  }
  if (d[idx] == 0) {
    if (idx == d.size() - 1) {
      d.pop_back();
    } else {
      d[idx] = 9;
      dec(d, idx + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> d = convert(n);
  int ans = dp(d);
#ifdef DEBUG
  cout << ans << endl;
#endif
  while (true) {
    int i = 0;
    while (d[i] == 9) {
      i++;
      continue;
    }
    if (i < d.size() - 1) {
      d[i] = 9;
      dec(d, i + 1);
      ans = max(ans, dp(d));
#ifdef DEBUG
      cout << ans << endl;
#endif
    } else {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
