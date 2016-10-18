using System;

namespace acs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var s = Console.ReadLine();

			var ans = Math.Min(s[0] - 'a', 26 - (s[0] - 'a'));
			for (int i = 1; i < s.Length; i++) {
				var dist = Math.Min(Math.Abs(s[i] - s[i - 1]), (s[i] > s[i - 1] ? 'z' - s[i] + (s[i - 1] - 'a') : s[i] - 'a' + ('z' - s[i - 1])) + 1);
				ans += dist;
			}

			Console.WriteLine(ans);
		}
	}
}
