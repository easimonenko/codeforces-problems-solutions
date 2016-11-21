// Problem Id: 3A

using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim();
            var x_s = line1[0] - 'a';
            var y_s = line1[1] - '0' - 1;
            var line2 = Console.ReadLine().Trim();
            var x_t = line2[0] - 'a';
            var y_t = line2[1] - '0' - 1;

            var diag = Math.Min(Math.Abs(x_s - x_t), Math.Abs(y_s - y_t));
            var diag_dir = x_s <= x_t
                ? (y_s <= y_t ? "RU" : "RD")
                : (y_s <= y_t ? "LU" : "LD");
            var vert = Math.Abs(y_s - y_t) - diag;
            var horiz = Math.Abs(x_s - x_t) - diag;
            var line = Math.Max(horiz, vert);
            var line_dir = horiz == line
                ? (x_s <= x_t ? "R" : "L")
                : (y_s <= y_t ? "U" : "D");
            var answer = diag + line;

            Console.WriteLine(answer);
            for (int i = 0; i < diag; i++) {
                Console.WriteLine(diag_dir);
            }
            for (int i = 0; i < line; i++) {
                Console.WriteLine(line_dir);
            }
        }
    }
}
