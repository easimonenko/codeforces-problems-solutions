using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line[0]);
            var m = Int32.Parse(line[1]);
            var a = Int32.Parse(line[2]);

            var w = n / a + (n % a == 0 ? 0 : 1);
            var h = m / a + (m % a == 0 ? 0 : 1);
            var answer = (long)w * (long)h;

            Console.WriteLine(answer);
        }
    }
}
