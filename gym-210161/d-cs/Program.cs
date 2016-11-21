// Problem Id: 10A

using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line[0]);
            var p1 = Int32.Parse(line[1]);
            var p2 = Int32.Parse(line[2]);
            var p3 = Int32.Parse(line[3]);
            var t1 = Int32.Parse(line[4]);
            var t2 = Int32.Parse(line[5]);

            var answer = 0;

            var last = 0;
            var lr = Console.ReadLine().Trim().Split();
            var l = Int32.Parse(lr[0]);
            var r = Int32.Parse(lr[1]);
            last = r;
            answer += (r - l) * p1;
            for (int i = 1; i < n; i++) {
                lr = Console.ReadLine().Trim().Split();
                l = Int32.Parse(lr[0]);
                r = Int32.Parse(lr[1]);

                answer += Math.Min(l - last, t1) * p1;
                answer += Math.Min(Math.Max(l - (last + t1), 0), t2) * p2;
                answer += Math.Max(l - (last + t1 + t2), 0) * p3;
                answer += (r - l) * p1;

                last = r;
            }

            Console.WriteLine(answer);
        }
    }
}
