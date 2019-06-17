#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> words(n);
  map<string, pair<int, char>> props;
  for (int i = 0; i < n; i++) {
    cin >> words[i];
    if (props.find(words[i]) == props.end()) {
      int c = 0;
      char w = ' ';
      for (int j = 0; j < words[i].length(); j++) {
        char ch = words[i][j];
        if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u') {
          c++;
          w = ch;
        }
      }
      props[words[i]] = make_pair(c, w);
    }
  }

  vector<vector<int>> answer;
  for (int ff = 0; ff < n; ff++) {
    for (int sf = 0; sf < n; sf++) {
      if (ff != sf && props[words[ff]] == props[words[sf]]) {
        for (int fs = 0; fs < n; fs++) {
          for (int ss = 0; ss < n; ss++) {
            if (fs != ss && props[words[fs]] == props[words[ss]] && fs != ff &&
                fs != sf && ss != ff && ss != sf) {
              vector<int> a = {ff, fs, sf, ss};
              answer.push_back(a);
            }
          }
        }
      }
    }
  }

  cout << answer.size() << endl;
  for (auto p : answer) {
    cout << words[p[0]] << ' ' << words[p[1]] << endl;
    cout << words[p[2]] << ' ' << words[p[3]] << endl;
  }

  return 0;
}
