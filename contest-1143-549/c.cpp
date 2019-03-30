#include <iostream>
#include <set>
#include <vector>

using namespace std;

enum color { white, gray, black };

bool check(vector<vector<int>> &tree, int u, set<int> &boors,
           set<int> &candidates) {
  // static vector<color> colors(tree.size());
  if (candidates.find(u) != candidates.end()) {
    return true;
  }
  // if (colors[u] == white) {
  // colors[u] = black;
  bool candidate = true;
  for (int i = 0; i < tree[u].size(); i++) {
    if (!(boors.find(tree[u][i]) != boors.end() /*&&
            dfs(tree, tree[u][i], boors, candidates)*/)) {
      candidate = false;
      break;
    }
  }
  if (candidate) {
    candidates.insert(u);
    return true;
  } else {
    return false;
  }
  //}
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> tree(n);
  set<int> boors;
  for (int i = 0; i < n; i++) {
    int p, c;
    cin >> p >> c;
    if (p != -1) {
      tree[p - 1].push_back(i);
    }
    if (c == 1) {
      boors.insert(i);
    }
  }

  set<int> candidates;
  set<int>::iterator boor_it = boors.begin();
  for (; boor_it != boors.end(); boor_it++) {
    int boor = *boor_it;
    check(tree, boor, boors, candidates);
  }

  if (candidates.size() == 0) {
    cout << "-1" << endl;
  } else {
    set<int>::iterator it = candidates.begin();
    cout << *it + 1;
    it++;
    for (; it != candidates.end(); it++) {
      cout << ' ' << *it + 1;
    }
    cout << endl;
  }

  return 0;
}
