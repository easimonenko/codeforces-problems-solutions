using System;

namespace ccs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var n = Int32.Parse(Console.ReadLine());

			var p = new int[n];
			for (int i = 0; i < n - 1; i++) {
				p[i] = i + 2;
			}
			p[n - 1] = 1;

			Console.WriteLine(String.Join(" ", p));
		}
	}
}
