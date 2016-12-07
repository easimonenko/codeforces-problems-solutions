// Problem Id: 22A

using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var line = Console.ReadLine().Trim().Split();

            var min = Int32.Parse(line[0]);
            int next = 101;
            for (int i = 1; i < n; i++) {
                var d = Int32.Parse(line[i]);
                if (d < min) {
                    next = min;
                    min = d;
                }
                else if ((next == 101 || d < next) && d != min) {
                    next = d;
                }
            }
                
            Console.WriteLine(next == 101 ? "NO" : next.ToString());
        }
    }
}
