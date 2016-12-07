// Problem Id: 27A

using System;

namespace fcs
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

            Array.Sort(a);

            var answer = a[0] > 1 ? 1 : 0;

            if (answer == 0) {
                for (int i = 0; i < n - 1; i++) {
                    if (a[i + 1] - a[i] > 1) {
                        answer = a[i] + 1;
                        break;
                    }
                }
            }

            if (answer == 0) {
                answer = a[n - 1] + 1;
            }


            Console.WriteLine(answer);
        }
    }
}
