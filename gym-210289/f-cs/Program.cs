// Problem Id: 17A

using System;
using System.Collections.Generic;

namespace fcs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var line = Console.ReadLine().Trim().Split();
            var n = Int32.Parse(line[0]);
            var k = Int32.Parse(line[1]);

            var m = 0;

            var eratosfen = new bool[n + 1];
            for (int i = 0; i <= n; i++) {
                eratosfen[i] = true;
            }
            eratosfen[0] = false;
            eratosfen[1] = false;
            for (int i = 2; i <= n; i++) {
                if (eratosfen[i]) {
                    for (int j = i + i; j <= n; j += i) {
                        eratosfen[j] = false;
                    }
                }
            }

            var primes = new List<int>();
            for (int i = 2; i <= n; i++) {
                if (eratosfen[i]) {
                    primes.Add(i);
                }
            }

            for (int q = 2; q < primes.Count; q++) {
                for (int r = q - 1; r > 1; r--) {
                    if (primes[q] == primes[r] + primes[r - 1] + 1) {
                        m += 1;
                    }
                }
            }

            Console.WriteLine(m >= k ? "YES" : "NO");
        }
    }
}
