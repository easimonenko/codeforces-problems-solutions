// Proble Id: 11A

using System;

namespace ecs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var d = Int32.Parse(line1[1]);

            var line2 = Console.ReadLine().Trim().Split();
            var b = new int[n];
            for (int i = 0; i < n; i++) {
                b[i] = Int32.Parse(line2[i]);
            }

            var answer = 0;

            for (int i = 1; i < n; i++) {
                int diff = b[i] - b[i - 1];
                if (diff <= 0) {
                    int k = Math.Abs(diff) / d;
                    answer += k + 1;
                    b[i] += (k + 1) * d;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
