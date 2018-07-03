#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<list<int>> pos(32);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    for (char alfa = 'a'; alfa <= 'z'; alfa++) {
        while (pos[alfa - 'a'].size() > 0 && k > 0) {
            s[pos[alfa - 'a'].front()] = 0;
            pos[alfa - 'a'].pop_front();
            k--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != 0) {
            cout << s[i];
        }
    }
    cout << endl;

    return 0;
}
