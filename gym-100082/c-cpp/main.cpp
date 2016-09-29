#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<bool> > &graph, vector<int> &used, int s) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 1; v < graph[u].size(); v++) {
			if (used[v] == 0 && graph[u][v]) {
				q.push(v);
				used[v] = used[u]+1;
			}
		}
	}
}

int main() {
#ifdef ONLINE_JUDGE
	freopen("bfs.in", "r", stdin);
	freopen("bfs.out", "w", stdout);
#endif
	int n, s, f;
	cin >> n >> s >> f;
	vector<vector<bool> > graph(n+1, vector<bool>(n+1));
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			int t;
			scanf("%d", &t);
			if (t == 1) {
				graph[u][v] = true;
			}
		}
	}

	vector<int> used(n+1);
	bfs(graph, used, s);

	cout << used[f] << endl;

	return 0;
}
