using System;
using System.IO;
using System.Collections.Generic;

namespace ccs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("bfs.in");
			writer = new StreamWriter("bfs.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			var input_n_s_f = reader.ReadLine().Split();
			var n = Int32.Parse(input_n_s_f[0]);
			var s = Int32.Parse(input_n_s_f[1]);
			var f = Int32.Parse(input_n_s_f[2]);

			var graph = new int[n,n];
			for (int i = 0; i < n; i++) {
				var line = reader.ReadLine().Split();
				for (int j = 0; j < n; j++) {
					graph[i,j] = line[j][0] - '0';
				}
			}

			writer.WriteLine(Solve(graph, s)[f - 1]);

			writer.Close();
		}

		private static int[] Solve(int[,] graph, int s) {
			var n = graph.GetLength(0);
			var ans = new int[n];

			var q = new Queue<int>();
			q.Enqueue(s - 1);
			while (q.Count != 0) {
				var next = q.Dequeue();
				for (int k = 0; k < graph.GetLength(0); k++) {
					if (graph[next, k] == 1 && ans[k] == 0) {
						ans[k] = ans[next] + 1;
						q.Enqueue(k);
					}
				}
			}

			return ans;
		}
	}
}
