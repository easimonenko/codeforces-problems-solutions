using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim();
            var B = 0;
            var u = 0;
            var l = 0;
            var b = 0;
            var a = 0;
            var s = 0;
            var r = 0;

            foreach (var c in line) {
                switch (c) {
                    case 'B':
                        B += 1;
                        break;
                    case 'u':
                        u += 1;
                        break;
                    case 'l':
                        l += 1;
                        break;
                    case 'b':
                        b += 1;
                        break;
                    case 'a':
                        a += 1;
                        break;
                    case 's':
                        s += 1;
                        break;
                    case 'r':
                        r += 1;
                        break;
                }
            }

            Console.WriteLine(
                Math.Min(B, Math.Min(u / 2, Math.Min(l, Math.Min(b, Math.Min(a / 2, Math.Min(s, r))))))
            );
        }
    }
}
