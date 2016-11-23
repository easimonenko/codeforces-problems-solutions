using System;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int64.Parse(line[0]);
            var a = Int64.Parse(line[1]);
            var b = Int64.Parse(line[2]);
            var c = Int64.Parse(line[3]);

            var r = n / 4 + (n % 4 == 0 ? 0 : 1);
            var k = r * 4 - n;

            if (k == 0) {
                Console.WriteLine(0);
            }
            else {
                var c_abc = k / 3;
                var b_abc = (k - c_abc) / 2;
                var a_abc = k - c_abc * 3 - b_abc * 2;
                var answer_abc = a * a_abc + b * b_abc + c * c_abc;

                var answer_a = k * a;

                var answer = Math.Min(answer_abc, answer_a);

                if (k % 2 == 0) {
                    answer = Math.Min(answer, (k / 2) * b);
                }
                    
                if (k % 3 == 0) {
                    answer = Math.Min(answer, (k / 3) * c);
                }

                var b_ab = k / 2;
                var a_ab = k - b_ab * 2;
                answer = Math.Min(answer, a_ab * a + b_ab * b);

                var c_ac = k / 3;
                var a_ac = k - c_ac * 3;
                answer = Math.Min(answer, a_ac * a + c_ac * c);

                var c_bc = k / 3;
                var b_bc = (k - c_bc * 3) / 2;
                if ((k - c_bc * 3) % 2 == 0) {
                    answer = Math.Min(answer, b_bc * b + c_bc * c);
                }

                Console.WriteLine(answer);
            }
        }
    }
}
