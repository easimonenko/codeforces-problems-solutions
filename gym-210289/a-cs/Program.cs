// Problem Id: 12A

using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim();
            var line2 = Console.ReadLine().Trim();
            var line3 = Console.ReadLine().Trim();

            var answer = true;

            if (line1[0] == 'X' && line3[2] != 'X') {
                answer = false;
            }

            if (line1[1] == 'X' && line3[1] != 'X') {
                answer = false;
            }

            if (line1[2] == 'X' && line3[0] != 'X') {
                answer = false;
            }

            if (line2[0] == 'X' && line2[2] != 'X') {
                answer = false;
            }

            if (line2[1] == 'X' && line2[1] != 'X') {
                answer = false;
            }

            if (line2[2] == 'X' && line2[0] != 'X') {
                answer = false;
            }

            if (line3[0] == 'X' && line1[2] != 'X') {
                answer = false;
            }

            if (line3[1] == 'X' && line1[1] != 'X') {
                answer = false;
            }

            if (line3[2] == 'X' && line1[0] != 'X') {
                answer = false;
            }

            Console.WriteLine(answer ? "YES" : "NO");
        }
    }
}
