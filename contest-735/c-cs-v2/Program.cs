using System;

namespace ccs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int64.Parse(Console.ReadLine().Trim());

            var answer = 0;

            if (n == 2) {
                answer = 1;
            }
            else if (n == 3) {
                answer = 2;
            }
            else {
                long fib = 3;
                long first = 2;
                long second = 3;
                answer = 2;
                while (fib < n) {
                    answer += 1;
                    fib = first + second;
                    first = second;
                    second = fib;
                }
                if (fib > n) {
                    answer -= 1;
                }
            }

            Console.WriteLine(answer);
        }
    }
}
