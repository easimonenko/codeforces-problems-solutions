using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var l = new int[n];
            var r = new int[n];
            var left = 0;
            var right = 0;
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Split();
                var li = Int32.Parse(line[0]);
                var ri = Int32.Parse(line[1]);
                l[i] = li;
                r[i] = ri;
                left += li;
                right += ri;
            }
                
            var best = Math.Abs(left - right);
            var idx = -1;
            for (int i = 0; i < n; i++) {
                var c = Math.Abs((left - l[i] + r[i]) - (right - r[i] + l[i]));
                if (c > best) {
                    idx = i;
                    best = c;
                }
            }

            Console.WriteLine(idx + 1);
        }
    }
}
