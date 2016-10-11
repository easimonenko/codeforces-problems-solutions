using System;
using System.Collections.Generic;

namespace bcs
{
	class MainClass
	{
		public static void Main(string[] args)
		{
			var digits = Console.ReadLine().Split();

			var basis = Math.Max(GetBasis(digits[0]), GetBasis(digits[1]));
			int number1 = ConvertToInt(digits[0], basis);
			int number2 = ConvertToInt(digits[1], basis);
			int summa = number1 + number2;
			Console.WriteLine(ConvertToString(summa, basis).Length);
		}

		static int GetBasis(string s)
		{
			int result = 0;

			foreach (var c in s) {
				result = Math.Max(result, Char.IsDigit(c) ? c - '0' : c - 'A' + 10);
			}

			return result + 1;
		}

		static int ConvertToInt(string s, int basis)
		{
			int result = 0;

			int d = 1;
			var char_list = new List<char>(s);
			char_list.Reverse();
			foreach (var c in char_list) {
				result += (Char.IsDigit(c) ? c - '0' : c - 'A' + 10) * d;
				d *= basis;
			}

			return result;
		}

		static string ConvertToString(int number, int basis)
		{
			var char_list = new List<char>();
			while (number != 0) {
				int digit = number % basis;
				char_list.Add((char)(digit < 10 ? digit + '0' : digit + 'A'));
				number /= basis;
			}
			char_list.Reverse();

			var result = new char[char_list.Count];
			int i = 0;
			foreach (var c in char_list) {
				result[i] = c;
				i++;
			}

			return new string(result);
		}
	}
}
