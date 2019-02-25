#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  long long ans = 0;
  vector<int> stations(0);
  stations.push_back(1);
  int k = 1;
  while (k != n) {

  }
  stations.push_back(n);

  cout << ans << stations.size() << endl;
  cout << stations[0];
  for (int j = 1; j < stations.size(); j++) {
    cout << " " << stations[j];
  }
  cout << endl;

  return 0;
}
