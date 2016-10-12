using System;

namespace dcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var n = Int32.Parse(Console.ReadLine());
			var s = Console.ReadLine();

			int zero_started = 0;
			int one_started = 0;

			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					if (s[i] == '1') {
						zero_started += 1;
					}
					else {
						one_started += 1;
					}
				}
				else {
					if (s[i] == '0') {
						zero_started += 1;
					}
					else {
						one_started += 1;
					}
				}
			}

			Console.WriteLine(Math.Min(zero_started, one_started));
		}
	}
}
