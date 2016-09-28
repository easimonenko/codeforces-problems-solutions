using System;
using System.IO;
using System.Collections.Generic;

namespace bcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("connect2.in");
			writer = new StreamWriter("connect2.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			int n, m;
			var input_n_m = reader.ReadLine().Split();
			n = Int32.Parse(input_n_m[0]);
			m = Int32.Parse(input_n_m[1]);

			var graph = new List<int>[n];
			for (int i = 0; i < n; i++) {
				graph[i] = new List<int>();
			}

			for (int k = 0; k < m; k++) {
				int u, v;
				var input_edge = reader.ReadLine().Split();
				u = Int32.Parse(input_edge[0]);
				v = Int32.Parse(input_edge[1]);
				graph[u - 1].Add(v - 1);
				graph[v - 1].Add(u - 1);
			}

			writer.WriteLine(Solve(graph));

			writer.Close();
		}

		private static int Solve(List<int>[] graph) {
			int ans = 0;

			var colors = new Color[graph.Length];
			for (int i = 0; i < graph.Length; i++) {
				colors[i] = Color.White;
			}

			for (int i = 0; i < graph.Length; i++) {
				if (colors[i] == Color.White) {
					ans += 1;
					DFS(graph, i, colors);
				}
			}

			return ans;
		}

		private static void DFS(List<int>[] graph, int u, Color[] colors) {
			colors[u] = Color.Gray;

			foreach (var v in graph[u]) {
				if (colors[v] == Color.White) {
					DFS(graph, v, colors);
				}
			}

			colors[u] = Color.Black;
		}

		private enum Color {
			White, Gray, Black
		}
	}
}
