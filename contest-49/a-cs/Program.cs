using System;

namespace acs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var question = Console.ReadLine();

			bool q_checked = false;
			for (int i = question.Length - 1; i >= 0 && !q_checked; i--) {
				switch (Check(question, i)) {
					case CheckResult.Vowel:
						Console.WriteLine("YES");
						q_checked = true;
						break;
					case CheckResult.Consonant:
						Console.WriteLine("NO");
						q_checked = true;
						break;
				}
			}
		}

		enum CheckResult
		{
			Vowel, Consonant, Other
		}

		static CheckResult Check(string s, int idx)
		{
			var result = CheckResult.Other;
			var ls = s.ToLower();
			switch (ls[idx]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y':
					result = CheckResult.Vowel;
					break;
				case 'b':
				case 'c':
				case 'd':
				case 'f':
				case 'g':
				case 'h':
				case 'j':
				case 'k':
				case 'l':
				case 'm':
				case 'n':
				case 'p':
				case 'q':
				case 'r':
				case 's':
				case 't':
				case 'v':
				case 'w':
				case 'x':
				case 'z':
					result = CheckResult.Consonant;
					break;
			}

			return result;
		}
	}
}
