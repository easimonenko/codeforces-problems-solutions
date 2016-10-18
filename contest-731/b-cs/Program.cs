using System;

namespace bcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var n = Int32.Parse(Console.ReadLine());
			var a = new int[n];
			var line = Console.ReadLine().Split();
			for (int i = 0; i < n; i++) {
				a[i] = Int32.Parse(line[i]);
			}

			bool ans = true;
			a[0] = a[0] % 2;
			for (int i = 1; i < n; i++) {
				if (a[i] == 0 && a[i - 1] != 0) {
					ans = false;
					break;
				}
				else if (a[i] % 2 == 0) {
					if (a[i - 1] == 0) {
						a[i] = 0;
					}
					else {
						a[i] = 1;
					}
				}
				else {
					if (a[i - 1] == 0) {
						a[i] = 1;
					}
					else {
						a[i] = 0;
					}
				}
			}

			if (ans) {
				Console.WriteLine(a[n - 1] % 2 == 0 ? "YES" : "NO");
			}
			else {
				Console.WriteLine("NO");
			}
		}
	}
}
