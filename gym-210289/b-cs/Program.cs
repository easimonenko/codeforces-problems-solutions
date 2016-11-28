// Problem Id: 13A

using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var a = Int32.Parse(Console.ReadLine().Trim());

            var s = 0;

            for (int i = 2; i <= a - 1; i++) {
                var ai = a;
                while (ai > 0) {
                    s += ai % i;
                    ai /= i;
                }
            }

            var d = GCD(Math.Max(s, a - 2), Math.Min(s, a - 2));

            Console.WriteLine("{0}/{1}", s / d, (a - 2) / d);
        }

        private static int GCD(int a, int b) {
            return b == 0 ? a : GCD(b, a % b);
        }
    }
}
