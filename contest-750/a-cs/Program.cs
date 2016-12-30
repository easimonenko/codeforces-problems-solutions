using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line[0]);
            var k = Int32.Parse(line[1]);

            var time = 4 * 60 - k;
            var realTime = 0;
            int i = 0;
            while (true) {
                if ((realTime += (i + 1) * 5) <= time) {
                    i += 1;
                }
                else {
                    break;
                }
            }

            Console.WriteLine(Math.Min(i, n));
        }
    }
}
