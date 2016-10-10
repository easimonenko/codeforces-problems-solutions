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
			reader = new StreamReader("topsort.in");
			writer = new StreamWriter("topsort.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			var input = reader.ReadLine().Split();
			int n = Int32.Parse(input[0]);
			int m = Int32.Parse(input[1]);

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
			}

			var answer = TopSort(graph);
			if (answer.Count == 0) {
				writer.WriteLine(-1);
			}
			else {
				answer.Reverse();
				var toOutput = new List<int>();
				foreach (var v in answer) {
					toOutput.Add(v + 1);
				}
				writer.WriteLine(String.Join(" ", toOutput));
			}

			writer.Close();
		}

		static List<int> TopSort(List<int>[] graph)
		{
			var result = new List<int>();

			var colors = new Color[graph.Length];
			for (int i = 0; i < graph.Length; i++) {
				colors[i] = Color.White;
			}

			for (int i = 0; i < graph.Length; i++) {
				if (colors[i] == Color.White) {
					if (!DFS(graph, i, colors, result)) {
						result = new List<int>();
						break;
					}
				}
			}

			return result;
		}

		static bool DFS(List<int>[] graph, int u, Color[] colors, List<int> result)
		{
			bool acyclic = true;

			colors[u] = Color.Gray;

			foreach (var v in graph[u]) {
				if (colors[v] == Color.White) {
					if (!DFS(graph, v, colors, result)) {
						acyclic = false;
						break;
					}
				}
				else if (colors[v] == Color.Gray) {
					acyclic = false;
					break;
				}
			}

			result.Add(u);

			colors[u] = Color.Black;

			return acyclic;
		}

		enum Color {
			White, Gray, Black
		}
	}
}
