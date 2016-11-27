using System;

namespace dcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var n = Int32.Parse(Console.ReadLine().Trim());

            var answer = 0;

            while (n >= 2) {
                var p = findMaxPrime(n);
                if (p == 1) {
                    break;
                }
                n -= p;
                answer += 1;
            }

            Console.WriteLine(answer);
        }

        private static int findMaxPrime(int n) {
            if (n <= 1) {
                return 1;
            }
            else {
                if (isPrime(n)) {
                    return n;
                }
                else {
                    if (n % 2 == 0) {
                        if ((n / 2) % 2 != 0) {
                            return findMaxPrime(n / 2);
                        }
                        else {
                            return findMaxPrime(n - 2);
                            //return 2;
                        }
                    }
                    else {
                        return findMaxPrime(n - 2);
                    }
                }
            }
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
