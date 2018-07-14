#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> cl;
  int a1, a2;
  cin >> a1;
  for (int i = 1; i < n; i++) {
    cin >> a2;
    if (a2 == 1) {
      cl.push_back(a1);
    }
    a1 = a2;
  }
  cl.push_back(a1);

  cout << cl.size() << endl;
  cout << cl[0];
  for_each(cl.begin() + 1, cl.end(), [](auto elem) {
      cout << ' ' << elem;
    });
  cout << endl;
  
  return 0;
}
