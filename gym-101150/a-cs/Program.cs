using System;
using System.IO;
using System.Collections.Generic;

namespace acs
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            const int MAX_N = 10001;
            var sieve = new bool[MAX_N];
            for (int i = 2; i < MAX_N; i++) {
                sieve[i] = true;
            }
            for (int i = 2; i < MAX_N; i++) {
                if (sieve[i]) {
                    for (int j = 2; i * j < MAX_N; j++) {
                        sieve[i * j] = false;
                    }
                }
            }
            var primes = new List<int>();
            for (int i = 0; i < MAX_N; i++) {
                if (sieve[i]) {
                    primes.Add(i);
                }
            }
            var summs = new int[primes.Count];
            summs[0] = primes[0];
            for (int k = 1; k < summs.Length; k++) {
                summs[k] = summs[k - 1] + primes[k];
            }

            StreamReader reader;
            #if (ONLINE_JUDGE)
            reader = new StreamReader("A.txt");
            #else
            reader = new StreamReader(Console.OpenStandardInput());
            #endif

            while (true) {
                var d = Int32.Parse(reader.ReadLine());
                if (d == 0) {
                    break;
                }
                else {
                    int answer = 0;

                    Console.WriteLine(answer);
                }
            }
        }
    }
}
