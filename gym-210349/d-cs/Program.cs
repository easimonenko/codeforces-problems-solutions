// Problem Id: 25A

using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var line = Console.ReadLine().Trim().Split();

            var a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Int32.Parse(line[i]);
            }

            var answer = 0;

            if (a[0] % 2 == 0 && a[1] % 2 == 0
                || a[0] % 2 == 0 && a[2] % 2 == 0
                || a[1] % 2 == 0 && a[2] % 2 == 0) {
                answer = FindOdd(a);
            }
            else {
                answer = FindEven(a);
            }

            Console.WriteLine(answer + 1);
        }

        private static int FindOdd(int[] a)
        {
            for (int i = 0; i < a.Length; i++) {
                if (a[i] % 2 != 0) {
                    return i;
                }
            }

            return -1;
        }

        private static int FindEven(int[] a)
        {
            for (int i = 0; i < a.Length; i++) {
                if (a[i] % 2 == 0) {
                    return i;
                }
            }

            return -1;
        }
    }
}
