using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());
            var line = Console.ReadLine().Trim().Split();
            var c = new int[n];
            var d = new int[n];
            var prevC = Int32.Parse(line[0]);
            var prevD = Int32.Parse(line[1]);
            c[0] = prevC;
            d[0] = prevD;
            bool impossible = false;
            bool infinity = prevD == 1;
            for (int i = 1; i < n; i++) {
                line = Console.ReadLine().Trim().Split();
                var nextC = Int32.Parse(line[0]);
                var nextD = Int32.Parse(line[1]);
                if ((prevC <= 0 && nextD - prevD < 0) || (prevC >= 0 && nextD - prevD > 0)) {
                    impossible = true;
                    break;
                }
                if (nextC < prevD || nextD == 2) {
                    infinity = false;
                }
                prevC = nextC;
                prevD = nextD;
                c[i] = prevC;
                d[i] = prevD;
            }

            if (impossible) {
                Console.WriteLine("Impossible");
            }
            else if (infinity) {
                Console.WriteLine("Infinity");
            }
            else if (n == 1) {
                Console.WriteLine(1899);
            }
            else {
                var rating = d[0] == 1 ? 1900 : 1899;

                for (int i = 1; i < n; i++) {
                    if (d[i] == 2 && d[i - 1] == 1) {
                        
                    }
                }
                Console.WriteLine(rating);
            }
        }
    }
}
