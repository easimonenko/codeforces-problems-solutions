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
			reader = new StreamReader("absum.in");
			writer = new StreamWriter("absum.out");
			#else
			reader = new StreamReader(Console.OpenStandardInput());
			writer = new StreamWriter(Console.OpenStandardOutput());
			#endif

			var input = reader.ReadLine().Split();
			int a = Int32.Parse(input[0]);
			int b = Int32.Parse(input[1]);

			writer.WriteLine(a + b);

			writer.Close();
		}
	}
}
