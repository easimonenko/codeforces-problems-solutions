#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<char> answer = {s[0]};
  int i = 1;
  while (i < n) {
    int last = answer.size() - 1;
    if ((last + 1) % 2 == 0) {
      answer.push_back(s[i]);
      i++;
    } else {
      if (s[i] != answer[last]) {
        answer.push_back(s[i]);
      }
      i++;
    }
  }
  cout << s.length() - answer.size() + (answer.size() % 2) << endl;
  for (int k = 0; k < answer.size() - (answer.size() % 2); k++) {
    cout << answer[k];
  }
  cout << endl;

  return 0;
}
