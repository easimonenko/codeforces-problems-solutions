using System;

namespace acs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var input = Console.ReadLine().Split(' ');

			var n = Int64.Parse(input[0]);
			var m = Int64.Parse(input[1]);
			var a = Int64.Parse(input[2]);

			Console.WriteLine(((n / a) + (n % a != 0 ? 1 : 0)) * ((m / a) + (m % a != 0 ? 1 : 0 )));
		}
	}
}
