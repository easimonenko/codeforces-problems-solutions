using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var lineWithA = Console.ReadLine().Trim().Split();
            var lineWithB = Console.ReadLine().Trim().Split();

            var n = Int32.Parse(line1[0]);
            var l = Int32.Parse(line1[1]);
            var r = Int32.Parse(line1[2]);
            var a = new int[n];
            var b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = Int32.Parse(lineWithA[i]);
            }
            for (int i = 0; i < n; i++) {
                b[i] = Int32.Parse(lineWithB[i]);
            }

            var answer = true;

            for (int i = 0; i < l - 1; i++) {
                if (a[i] != b[i]) {
                    answer = false;
                    break;
                }
            }
            for (int i = r; i < n; i++) {
                if (a[i] != b[i]) {
                    answer = false;
                    break;
                }
            }

            Console.WriteLine(answer ? "TRUTH" : "LIE");
        }
    }
}
