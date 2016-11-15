using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var line2 = Console.ReadLine().Trim().Split();
            var line3 = Console.ReadLine().Trim().Split();
            var line4 = Console.ReadLine().Trim().Split();
            var line5 = Console.ReadLine().Trim().Split();
            var line6 = Console.ReadLine().Trim().Split();

            var n = Int32.Parse(line1[0]);
            var m = Int32.Parse(line1[1]);
            var k = Int32.Parse(line1[2]);

            var x = Int32.Parse(line2[0]);
            var s = Int32.Parse(line2[1]);

            var a = new int[m];
            for (int i = 0; i < m; i++) {
                a[i] = Int32.Parse(line3[i]);
            }

            var b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = Int32.Parse(line4[i]);
            }

            var c = new int[k];
            for (int i = 0; i < m; i++) {
                b[i] = Int32.Parse(line4[i]);
            }
        }
    }
}
