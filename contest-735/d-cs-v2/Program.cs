using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            var answer = (
                n == 2 
                ? 1 
                : (
                    n % 2 == 0 
                    ? 2
                    : (
                        isPrime(n)
                        ? 1
                        : (
                            isPrime(n - 2)
                            ? 2
                            : 3))));

            Console.WriteLine(answer);
        }

        private static bool isPrime(int n) {
            if (n == 1) {
                return false;
            }

            if (n == 2) {
                return true;
            }

            if (n % 2 == 0) {
                return false;
            }

            bool answer = true;

            for (int k = 3; (long)k * k <= (long)n; k += 2) {
                if (n % k == 0) {
                    answer = false;
                    break;
                }
            }

            return answer;
        }
    }
}