// TODO: buggy solution.

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

template<typename T> void printv(vector<T>& v, size_t n = 0) {
  cout << v[0];
  size_t l = n == 0 ? v.size() : min(n, v.size());
  for (size_t i = 1; i < l; i++) {
    cout << " " << v[i];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  vector<bool> primes(2 * 100000 + 1, true);
  primes[0] = false;
  primes[1] = false;
  size_t l = primes.size();
  for (size_t i = 2; i < l / 2; i++) {
    for (size_t j = 2; i * j < l; j++) {
      primes[i * j] = false;
    }
  }
  #ifdef DEBUG
  printv(primes, 100);
  #endif
  while (t-- > 0) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1";
    } else {
      cout << "2";
      for (size_t i = 3; i <= n; i++) {
        if (primes[i]){
          cout << " " << i;
        }
      }
      cout << " " << "1";
      for (size_t i = 3; i <= n; i++) {
        if (!primes[i]){
          cout << " " << i;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
