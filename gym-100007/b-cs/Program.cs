using System;
using System.IO;

namespace bcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			StreamReader reader;
			StreamWriter writer;
			#if (ONLINE_JUDGE)
			reader = new StreamReader("input.txt");
			writer = new StreamWriter("output.txt");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif
			long n = Int64.Parse(reader.ReadLine());
			int counter = 0;
			long k = 2;
			while (k * k * k * k <= n) {
				int c = 0;
				for (int d = 2; d <= k; d++) {
					if (k % d == 0) {
						c += 1;
					}
					if (c > 1) {
						break;
					}
				}
				if (c == 1) {
					counter++;
				}
				k++;
			}
			writer.WriteLine(counter);

			writer.Close();
		}
	}
}
