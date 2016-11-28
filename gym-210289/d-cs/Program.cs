// Problem Id: 15A

using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var t = Int32.Parse(line1[1]);

            var answer = 2;

            var x = new int[n];
            var a = new int[n];
            for (int i = 0; i < n; i++) {
                var line_i = Console.ReadLine().Trim().Split();
                x[i] = Int32.Parse(line_i[0]);
                a[i] = Int32.Parse(line_i[1]);
            }

            Array.Sort(x, a);

            for (int i = 0; i < n - 1; i++) {
                var d = (x[i + 1] - a[i + 1] / 2.0) - (x[i] + a[i] / 2.0);
                if (d > t) {
                    answer += 2;
                }
                else if (d == t) {
                    answer += 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
