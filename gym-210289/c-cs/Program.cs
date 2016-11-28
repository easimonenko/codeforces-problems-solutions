// Problem Id: 14A

using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var m = Int32.Parse(line1[1]);

            var x1 = m - 1;
            var y1 = n - 1;
            var x2 = 0;
            var y2 = 0;

            var flag = new string[n];

            for (int i = 0; i < n; i++) {
                flag[i] = Console.ReadLine().Trim();
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (flag[i][j] == '*') {
                        if (i < y1) {
                            y1 = i;
                        }
                        if (j < x1) {
                            x1 = j;
                        }
                        if (i > y2) {
                            y2 = i;
                        }
                        if (j > x2) {
                            x2 = j;
                        }
                    }
                }
            }

            for (int i = y1; i <= y2; i++) {
                for (int j = x1; j <= x2; j++) {
                    Console.Write(flag[i][j]);
                }
                Console.WriteLine();
            }
        }
    }
}
