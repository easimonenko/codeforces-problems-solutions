using System;
using System.IO;

namespace acs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("lis.in");
			writer = new StreamWriter("lis.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			int n = Int32.Parse(reader.ReadLine());
			var s = new int[n];
			char[] delimeters = { ' ' };
			var input = reader.ReadLine().Split(delimeters, n);
			for (int i = 0; i < n; i++) {
				s[i] = Int32.Parse(input[i]);
			}

			writer.WriteLine(Solve(s));

			writer.Close();
		}

		public static int Solve(int[] s)
		{
			int ans = 1;

			var d = new int[s.Length];
			d[0] = 1;
			for (int i = 1; i < s.Length; i++) {
				int local_ans = 0;
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] < s[i] && d[j] > local_ans) {
						local_ans = d[j];
					}
				}
				d[i] = local_ans + 1;
			}

			for (int i = 0; i < s.Length; i++) {
				if (d[i] > ans) {
					ans = d[i];
				}
			}

			return ans;
		}
	}
}
