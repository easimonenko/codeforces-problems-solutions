#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<set<int> > &graph, vector<bool> &used, int u) {
	used[u] = true;
	for (set<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++) {
		int v = *it;
		if (!used[v]) {
			dfs(graph, used, v);
		}
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("connect2.in", "r", stdin);
	freopen("connect2.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<set<int> > graph(n+1, set<int>());
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u != v) {
			graph[u].insert(v);
			graph[v].insert(u);
		}
	}

	int counter = 0;
	vector<bool> used(n+1);
	for (int u = 1; u <= n; u++) {
		if (!used[u]) {
			counter++;
			dfs(graph, used, u);
		}
	}

	cout << counter << endl;

	return 0;
}
