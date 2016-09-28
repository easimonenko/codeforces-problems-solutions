using System;
using System.Collections.Generic;
using System.Text;

namespace bcs
{
	struct Coord
	{
		enum CoordType {
			RC, AD
		}

		private int Row;
		private int Column;
		private CoordType Type;

		public Coord(string input)
		{
			if (input[0] == 'R' && ('0' <= input[1] && input[1] <= '9')) {
				int idxOfC = -1;
				for (int i = 2; i < input.Length; i++) {
					if (input[i] == 'C') {
						idxOfC = i;
						break;
					}
				}
				if (idxOfC != -1) {
					this.Row = Int32.Parse(input.Substring(1, idxOfC - 1));
					this.Column = Int32.Parse(input.Substring(idxOfC + 1));
					this.Type = CoordType.RC;
					return;
				}
			}

			int idxOfDigit = 1;
			for (; idxOfDigit < input.Length; idxOfDigit++) {
				if ('0' <= input[idxOfDigit] && input[idxOfDigit] <= '9') {
					break;
				}
			}

			this.Column = 0;
			int d = 1;
			for (int i = idxOfDigit - 1; i >= 0; i--) {
				this.Column += (input[i] - 'A' + 1) * d;
				d *= 26;
			}

			this.Row = Int32.Parse(input.Substring(idxOfDigit));

			this.Type = CoordType.AD;
		}

		public Coord Convert()
		{
			switch (this.Type) {
				case CoordType.AD:
					this.Type = CoordType.RC;
					break;
				case CoordType.RC:
					this.Type = CoordType.AD;
					break;
			}
			return this;
		}

		static string ToAlphabetical(int number)
		{
			var stack = new Stack<char>();
			while (number > 0) {
				char c;
				int z = number % 26;
				number /= 26;
				if (z == 0) {
					c = 'Z';
					number -= 1;
				}
				else {
					c = (char)('A' + z - 1);
				}
				stack.Push(c);
			}
			var str = new StringBuilder();
			while (stack.Count != 0) {
				str.Append(stack.Pop());
			}
			return str.ToString();
		}

		public override string ToString()
		{
			string str = "";
			switch (this.Type) {
				case CoordType.RC:
					str = "R" + this.Row + "C" + this.Column;
					break;
				case CoordType.AD:
					str = ToAlphabetical(this.Column) + this.Row;
					break;
			}
			return str;
		}
	}

	class MainClass
	{
		public static void Main(string[] args)
		{
			var n = Int32.Parse(Console.ReadLine());
			for (int k = 0; k < n; k++) {
				var coord = new Coord(Console.ReadLine());
				Console.WriteLine(coord.Convert());
			}
		}
	}
}
