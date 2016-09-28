#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n = 0, m = 0, a = 0;

    cin >> n >> m >> a;

    cout << (long long)(n / a + (n % a == 0 ? 0 : 1)) * (long long)(m / a + (m % a == 0 ? 0 : 1)) << endl;

    return 0;
}
