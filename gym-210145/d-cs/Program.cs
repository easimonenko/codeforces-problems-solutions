using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var w = Int32.Parse(Console.ReadLine().Trim());

            var answer = ((w - 2) % 2 == 0) && (w - 2 > 0) ? "YES" : "NO";

            Console.WriteLine(answer);
        }
    }
}
