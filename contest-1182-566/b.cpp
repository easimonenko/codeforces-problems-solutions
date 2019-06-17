#include <iostream>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> pic(h + 2, vector<char>(w + 2, '.'));
  for (int i = 0; i < h; i++) {
    string l;
    cin >> l;
    for (int j = 0; j < w; j++) {
      pic[i + 1][j + 1] = l[j];
    }
  }

  bool found = false;
  int cr = -1, cc = -1;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (pic[i][j] == '*') {
        if (pic[i - 1][j] == '*' && pic[i + 1][j] == '*' &&
            pic[i][j - 1] == '*' && pic[i][j + 1] == '*') {
          found = true;
          pic[i][j] = '.';
          cr = i;
          cc = j;
          break;
        }
      }
    }
    if (found) {
      break;
    }
  }
  if (found) {
    for (int i = cr - 1; i > 0; i--) {
      if (pic[i][cc] == '.') {
        break;
      } else {
        pic[i][cc] = '.';
      }
    }
    for (int i = cr + 1; i <= h; i++) {
      if (pic[i][cc] == '.') {
        break;
      } else {
        pic[i][cc] = '.';
      }
    }
    for (int j = cc - 1; j > 0; j--) {
      if (pic[cr][j] == '.') {
        break;
      } else {
        pic[cr][j] = '.';
      }
    }
    for (int j = cc + 1; j <= w; j++) {
      if (pic[cr][j] == '.') {
        break;
      } else {
        pic[cr][j] = '.';
      }
    }
  }

  bool others = false;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (pic[i][j] == '*') {
        others = true;
      }
    }
  }

  if (found && !others) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
