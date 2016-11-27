using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var k = Int32.Parse(line1[1]);
            var stripe = Console.ReadLine().Trim();

            var g = 0;
            var t = 0;
            for (int i = 0; i < n; i++) {
                if (stripe[i] == 'G') {
                    g = i;
                }
                else if (stripe[i] == 'T') {
                    t = i;
                }
            }

            var answer = false;

            if (g < t) {
                for (int i = g + k; i < n; i += k) {
                    if (stripe[i] == 'T') {
                        answer = true;
                        break;
                    }
                    else if (stripe[i] == '#') {
                        break;
                    }
                }
            }
            else if (g > t) {
                for (int i = g - k; i >= 0; i -= k) {
                    if (stripe[i] == 'T') {
                        answer = true;
                        break;
                    }
                    else if (stripe[i] == '#') {
                        break;
                    }
                }
            }

            Console.WriteLine(answer ? "YES" : "NO");
        }
    }
}
