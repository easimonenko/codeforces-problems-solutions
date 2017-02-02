using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line1 = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line1[0]);
            var k = Int32.Parse(line1[1]);

            var l = new int[n];
            var r = new int[n];

            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Trim().Split();
                l[i] = Int32.Parse(line[0]);
                r[i] = Int32.Parse(line[1]);
            }

            var ll = l[0];
            var rr = r[0];
            var answer_co = new int[k];
            var answer_length = 0;
            var C = new int[k];
            Co(l, r, C, 0, 0, ll, rr, ref answer_length, answer_co);

            if (ll > rr) {
                Console.WriteLine("0");
                Console.Write("1");
                for (int i = 2; i <= k; i++) {
                    Console.Write(" {0}", i);
                }
                Console.WriteLine();
            }
            else {
                Console.WriteLine(rr - ll + 1);
                Console.Write(answer_co[0] + 1);
                for (int i = 1; i < k; i++) {
                    Console.Write(" {0}", answer_co[i] + 1);
                }
                Console.WriteLine();
            }
        }

        private static void Co(int[] left, int[] right, int[] C, int r, int m, int ll, int rr, ref int answer_length, int[] answer_co) {
            if (r == C.Length) {
                var answer = ll > rr ? 0 : rr - ll + 1;
                if (answer > answer_length) {
                    answer_length = answer;
                    for (int k = 0; k < C.Length; k++) {
                        answer_co[k] = C[k];
                    }
                }
            }
            else {
                for (int i = m; i < left.Length; i++) {
                    var next_ll = ll;
                    C[r] = i;
                    if (left[C[r]] > ll) {
                        next_ll = left[C[r]];
                    }
                    var next_rr = rr;
                    if (right[C[r]] < rr) {
                        next_rr = right[C[r]];
                    }
                    Co(left, right, C, r + 1, i + 1, next_ll, next_rr, ref answer_length, answer_co);
                }
            }
        }
    }
}
