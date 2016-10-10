using System;
using System.IO;

namespace ccs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("right.in");
			writer = new StreamWriter("right.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			var input = reader.ReadLine().Split();
			int n = Int32.Parse(input[0]);
			int m = Int32.Parse(input[1]);

			var x = new int[n];
			var input_x = reader.ReadLine().Split();
			for (int i = 0; i < n; i++) {
				x[i] = Int32.Parse(input_x[i]);
			}

			for (int k = 0; k < m; k++) {
				var query = Int32.Parse(reader.ReadLine());
				writer.WriteLine(BinSearch(x, query, 0, x.Length - 1) + 1);
			}

			writer.Close();
		}

		static int BinSearch(int[] x, int query, int left, int right)
		{
			int result = -1;

			if (left < 0 || right > x.Length - 1 || left > right) {
				return -1;
			}

			int middle = (left + right) / 2;
			if (x[middle] == query) {
				if (middle != x.Length - 1 && x[middle + 1] == query) {
					result = BinSearch(x, query, middle + 1, x.Length - 1);
				}
				else {
					result = middle;
				}
			}
			else if (x[middle] < query) {
				result = BinSearch(x, query, middle + 1, right);
			}
			else if (x[middle] > query) {
				result = BinSearch(x, query, left, middle - 1);
			}

			return result;
		}
	}
}
