using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var s = Console.ReadLine().Trim();
            int a = 0, d = 0;
            foreach (var c in s) {
                switch (c) {
                    case 'A':
                        a += 1;
                        break;
                    case 'D':
                        d += 1;
                        break;
                }
            }

            Console.WriteLine(a > d ? "Anton" : (a < d ? "Danik" : "Friendship"));
        }
    }
}
