using System;
using System.Collections.Generic;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine());
            var input1 = Console.ReadLine().Split();
            var a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Int32.Parse(input1[i]);
            }
            var k = Int32.Parse(Console.ReadLine());
            var input2 = Console.ReadLine().Split();
            var b = new int[k];
            for (int j = 0; j < k; j++) {
                b[j] = Int32.Parse(input2[j]);
            }

            bool possible = true;
            int l = 0;
            for (int j = 0; j < k; j++) {
                var aj = new List<int>();
                var sum = 0;
                for (; l < n; l++) {
                    sum += a[l];
                    if (sum > b[j]) {
                        break;
                    }
                    else {
                        aj.Add(a[l]);
                    }
                }
                if (sum != b[j]) {
                    possible = false;
                    break;
                }
                else {
                    
                }
            }

            if (possible) {
                var answer = Solve(a, 0, n - 1, b, 0, k - 1);
                if (answer.Count > 0) {
                    Console.WriteLine("YES");
                    for (int r = 0; r < answer.Count; r++) {
                        Console.WriteLine("{0} {1}", answer[r].idx, answer[r].dir);
                    }
                }
                else {
                    Console.WriteLine("NO");
                }
            }
            else {
                Console.WriteLine("NO");
            }
        }

        static List<Pair> Solve(int[] a, int a_begin, int a_end, int[] b, int b_begin, int b_end)
        {
            if (b_begin == b_end)
        }

        struct Pair
        {
            public int idx;
            public char dir;
            public Pair(int idx, char dir) {
                this.idx = idx;
                this.dir = dir;
            }
        }
    }
}
