#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> odd_elems, even_elems;
  for (int i = 0; i < n; i++) {
    int elem;
    cin >> elem;
    if (elem % 2 == 0) {
      even_elems.push_back(elem);
    } else {
      odd_elems.push_back(elem);
    }
  }

  int ans = 0;
  sort(odd_elems.begin(), odd_elems.end());
  sort(even_elems.begin(), even_elems.end());

  if (odd_elems.size() == even_elems.size() ||
      abs((int)odd_elems.size() - (int)even_elems.size()) == 1) {
    ans = 0;
  } else if (odd_elems.size() > even_elems.size()) {
    int max_idx = odd_elems.size() - even_elems.size() - 1;
    for (int i = 0; i < max_idx; i++) {
      ans += odd_elems[i];
    }
  } else {
    int max_idx = even_elems.size() - odd_elems.size() - 1;
    for (int i = 0; i < max_idx; i++) {
      ans += even_elems[i];
    }
  }

  cout << ans << endl;

  return 0;
}
