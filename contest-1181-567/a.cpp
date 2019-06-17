#include <iostream>

using namespace std;

int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long r1 = x % z, r2 = y % z;
  long long r = r1 + r2;
  long long delta = r % z;
  cout << x / z + y / z + r / z << " " << max(min(r1, r2) - delta, 0LL) << endl;
  return 0;
}
