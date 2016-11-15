using System;
using System.Collections.Generic;

namespace acs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var n = Int32.Parse(Console.ReadLine());

			var gamers = new Dictionary<string, int>();
			var input = Console.ReadLine().Split();
			var winner_name = input[0];
			var winner_score = Int32.Parse(input[1]);
			gamers[winner_name] = winner_score;
			for (int i = 1; i < n; i++) {
				input = Console.ReadLine().Split();
				var current_name = input[0];
				var current_score = Int32.Parse(input[1]);
				if (gamers.ContainsKey(current_name)) {
					gamers[current_name] += current_score;
				}
				else {
					gamers.Add(current_name, current_score);
				}
				if (gamers[current_name] > winner_score) {
					winner_score = gamers[current_name];
					winner_name = current_name;
				}
			}

			Console.WriteLine(winner_name);
		}
	}
}
