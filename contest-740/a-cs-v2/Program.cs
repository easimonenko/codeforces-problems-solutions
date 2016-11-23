using System;

namespace acsv2
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int64.Parse(line[0]);
            var a = Int64.Parse(line[1]);
            var b = Int64.Parse(line[2]);
            var c = Int64.Parse(line[3]);

            long answer = 0;

            if (n % 4 == 0) {
                answer = 0;
            }
            else if ((n + 1) % 4 == 0) {
                answer = a;
            }
            else if ((n + 2) % 4 == 0) {
                answer = Math.Min(a * 2, b);
            }
            else if ((n + 3) % 4 == 0) {
                answer = Math.Min(Math.Min(a * 3, a + b), c);
            }

            Console.WriteLine(answer);
        }
    }
}
