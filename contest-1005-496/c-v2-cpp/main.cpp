#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  map<long long,int> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    v[a[i]]++;
  }

  vector<long long> d;
  d.push_back(1);
  for (int i = 1; i < 32; i++) {
    d.push_back(d[i-1] << 1);
  }

  int ans = 0;
  for_each(a.begin(), a.end(), [&ans,d,&v](auto elem) {
      bool no = true;
      for (int k = 0; k < d.size(); k++) {
	long long r = d[k] - elem;
	if (r == elem && v[elem] == 1) {
	  continue;
	}
	if (r > 0 && v.find(r) != v.end()) {
	  no = false;
	  break;
	}
      }
      if (no) {
	ans++;
      }
      //v.insert(elem);
    });
  cout << ans << endl;
  
  return 0;
}
