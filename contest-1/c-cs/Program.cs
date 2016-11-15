using System;

namespace ccs
{
	struct Pair {
		public double x;
		public double y;
		public Pair(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	class MainClass
	{
		public static void Main(string[] args)
		{
			var coords = new Pair[3];
			for (int i = 0; i < 3; i++) {
				var input = Console.ReadLine().Split();
				coords[i] = new Pair(Double.Parse(input[0]), Double.Parse(input[1]));
			}


		}
	}
}
