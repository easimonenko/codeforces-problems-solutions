using System;
using System.IO;

namespace kcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("ladder.in");
			writer = new StreamWriter("ladder.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			var n = Int32.Parse(reader.ReadLine());
			var ladder = new int[n + 2];
			ladder[0] = 0; ladder[n + 1] = 0;
			var input = reader.ReadLine().Split();
			for (int i = 1; i <= n; i++) {
				ladder[i] = Int32.Parse(input[i - 1]);
			}
			var k = Int32.Parse(reader.ReadLine());

			var d = new int[k, n + 2];
			var a = new bool[k, n + 2];
			for (int i = 1; i < n + 2; i++) {
				d[0, i] = d[0, i - 1] + ladder[i];
				a[0, i] = true;
			}
			for (int r = 1; r < k; r++) {
				for (int j = r + 1; j < n + 2; j++) {
					int best = d[0, j];
					for (int i = 1; i <= r; i++) {
						if (a[i, j] && d[i, j] > best) {
							best = d[i, j];
						}
					}
					d[r, j] = best + ladder[j];
					a[r, j] = true;
				}
			}


			int answer = 0;
			for (int j = 0; j < k; j++) {
				if (d[j, n + 1] > answer) {
					answer = d[j, n + 1];
				}
			}

			writer.WriteLine(answer);

			writer.Close();
		}
	}
}
