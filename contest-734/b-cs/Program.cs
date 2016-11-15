using System;

namespace bcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var kin = Console.ReadLine().Split();
            var k2 = Int32.Parse(kin[0]);
            var k3 = Int32.Parse(kin[1]);
            var k5 = Int32.Parse(kin[2]);
            var k6 = Int32.Parse(kin[3]);

            var ans = 0;
            var r1 = Math.Min(k2, Math.Min(k5, k6));
            ans += r1 * 256;
            k2 -= r1; k5 -= r1; k6 -= r1;
            var r2 = Math.Min(k2, k3);
            ans += r2 * 32;

            Console.WriteLine(ans);
        }
    }
}
