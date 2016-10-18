using System;
using System.Collections.Generic;

namespace ccs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var line1 = Console.ReadLine().Split();
			var n = Int32.Parse(line1[0]);
			var m = Int32.Parse(line1[1]);
			var k = Int32.Parse(line1[2]);
			var colors = new int[n];
			var line2 = Console.ReadLine().Split();
			for (int i = 0; i < n; i++) {
				colors[i] = Int32.Parse(line2[i]) - 1;
			}

			var graph = new List<int>[n];
			for (int i = 0; i < n; i++) {
				graph[i] = new List<int>();
			}
			for (int j = 0; j < m; j++) {
				var edge = Console.ReadLine().Split();
				var u = Int32.Parse(edge[0]) - 1;
				var v = Int32.Parse(edge[1]) - 1;
				graph[u].Add(v);
				graph[v].Add(u);
			}

			var ans = 0;
			var dfsColors = new Color[n];
			var connectedComponents = new int[n];
			int ccNumber = 0;
			for (int u = 0; u < n; u++) {
				if (dfsColors[u] == Color.White) {
					ccNumber++;
					DFS(graph, u, dfsColors, connectedComponents, ccNumber);

				}
			}

			for (int ccIndex = 1; ccIndex <= ccNumber; ccIndex++) {
				var colorsInC = new int[k];
				var ccCount = 0;
				for (int u = 0; u < n; u++) {
					if (connectedComponents[u] == ccIndex) {
						colorsInC[colors[u]]++;
						ccCount++;
					}
				}

				var bestColorCount = 0;
				var notNullColorsCount = 0;
				foreach (var count in colorsInC) {
					if (count != 0) {
						notNullColorsCount++;
						if (count > bestColorCount) {
							bestColorCount = count;
						}
					}
				}
				ans += ccCount - bestColorCount;
			}

			Console.WriteLine(ans);
		}

		enum Color
		{
			White, Gray, Black
		}

		static void DFS(List<int>[] graph, int u, Color[] colors, int[] connectedComponents, int ccNumber)
		{
			colors[u] = Color.Gray;

			connectedComponents[u] = ccNumber;

			foreach (var v in graph[u]) {
				if (colors[v] == Color.White) {
					DFS(graph, v, colors, connectedComponents, ccNumber);
				}
			}

			colors[u] = Color.Black;
		}
	}
}
