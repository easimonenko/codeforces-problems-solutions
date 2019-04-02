#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  sort(a.begin(), a.end());
  vector<int> first, second;
  int elem = a[0];
  first.push_back(elem);
  int elem_counter = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == elem) {
      second.push_back(elem);
      elem_counter++;
    } else {
      elem = a[i];
      first.push_back(elem);
      elem_counter = 1;
    }
    if (elem_counter > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  puts("YES");
  cout << first.size() << endl;
  if (first.size() > 0) {
    cout << first[0];
    for (int k = 1; k < first.size(); k++) {
      printf(" %d", first[k]);
    }
  }
  cout << endl;

  reverse(second.begin(), second.end());
  cout << second.size() << endl;
  if (second.size() > 0) {
    cout << second[0];
    for (int k = 1; k < second.size(); k++) {
      printf(" %d", second[k]);
    }
  }
  cout << endl;

  return 0;
}
