using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var n1 = Int32.Parse(line1[1]);
            var n2 = Int32.Parse(line1[2]);
            var line2 = Console.ReadLine().Trim().Split();
            var a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Int32.Parse(line2[i]);
            }

            Array.Sort(a);

            long sum1_first = 0;
            for (int i = n - n1; i < n; i++) {
                sum1_first += a[i];
            }
            long sum1_second = 0;
            for (int i = n - n1 - n2; i < n - n1; i++) {
                sum1_second += a[i];
            }

            long sum2_first = 0;
            for (int i = n - n2; i < n; i++) {
                sum2_first += a[i];
            }
            long sum2_second = 0;
            for (int i = n - n1 - n2; i < n - n2; i++) {
                sum2_second += a[i];
            }

            long sum1 = (long)sum1_first * n2 + (long)sum1_second * n1;
            long sum2 = (long)sum2_first * n1 + (long)sum2_second * n2;

            double ans1 = sum1 / (double)((long)n1 * n2);
            double ans2 = sum2 / (double)((long)n1 * n2);

            Console.WriteLine(Math.Max(ans1, ans2).ToString().Replace(",", "."));
        }
    }
}
