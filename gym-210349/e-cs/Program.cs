// Problem Id: 26A

using System;

namespace ecs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            var e = new bool[n + 1];
            for (int i = 0; i < e.Length; i++) {
                e[i] = true;
            }
            e[0] = false;
            e[1] = false;

            for (int i = 2; i < e.Length; i++) {
                if (e[i]) {
                    for (int j = 2 * i; j < e.Length; j += i) {
                        e[j] = false;
                    }
                }
            }

            var answer = 0;

            for (int k = 1; k <= n; k++) {
                var c = 0;
                for (int d = 2; d <= k / 2; d++) {
                    if (e[d] && k % d == 0) {
                        c += 1;
                    }
                }
                if (c == 2) {
                    answer += 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
