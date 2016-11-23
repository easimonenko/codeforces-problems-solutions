using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var m = Int32.Parse(line1[1]);
            var line2 = Console.ReadLine().Trim().Split();
            var a = new int[n];
            var sum = new int[n];
            a[0] = Int32.Parse(line2[0]);
            sum[0] = a[0];
            for (int i = 1; i < n; i++) {
                a[i] = Int32.Parse(line2[i]);
                sum[i] = sum[i - 1] + a[i];
            }
            var answer = 0;
            while (m > 0) {
                var lr = Console.ReadLine().Trim().Split();
                var l = Int32.Parse(lr[0]) - 1;
                var r = Int32.Parse(lr[1]) - 1;
                var s = sum[r] - sum[l] + a[l];
                answer += Math.Max(s, 0);
                m -= 1;
            }

            Console.WriteLine(answer);
        }
    }
}
